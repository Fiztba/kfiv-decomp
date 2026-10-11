/* Effect actors: short-lived effects that move a model and end in another effect. */
#ifndef KF_EFFECT_H
#define KF_EFFECT_H

#include "common.h"
#include "kf_model.h"

/* the effect's definition, EffectActor.def */
typedef struct {
    char pad00[0xEC];
    u16 radius_half;                /* 0xEC */
    u16 interval;                   /* 0xEE frames between collision checks */
    char padF0[0x14];
    f32 gravity;                    /* 0x104 */
    u16 max_frames;                 /* 0x108 0: no limit */
    char pad10A[0x0E];
    u16 end_effect;                 /* 0x118 spawned when the effect ends */
} EffectDef;

/* EffectActor+0x10, which the update functions keep a pointer to. Each kind of
   effect uses the bytes after the velocity its own way; the *Motion types below
   are those views, reached by a cast (a union changes gcc's scheduling). */
typedef struct {
    Vector4 velocity;               /* 0x00 (EffectActor+0x10) */
    char unk10[0x28];               /* 0x10 per-kind state */
} EffectMotion;

/* EffectMotion as func_001A4CE8 uses it */
typedef struct {
    Vector4 velocity;               /* 0x00 */
    u16 end_frame;                  /* 0x10 */
    char pad12[0x26];
} ProjectileMotion;

/* EffectMotion as func_001A96B0 (falls under gravity) uses it */
typedef struct {
    Vector4 velocity;               /* 0x00 */
    int mode;                       /* 0x10 3 or 5: spawn effect 0x15 on landing */
    u16 end_frame;                  /* 0x14 */
    char pad16;
    char unk17[0x21];               /* 0x17 passed by address */
} FallingMotion;

/* EffectMotion as func_001A98D0 (checks for hits every interval frames) uses it */
typedef struct {
    Vector4 velocity;               /* 0x00 */
    char pad10[0x04];
    int countdown;                  /* 0x14 frames to the next check */
    char unk18[0x20];               /* 0x18 passed by address */
} EmitterMotion;

/* EffectMotion as func_001AC1F8 (scales its model) uses it */
typedef struct {
    Vector4 velocity;               /* 0x00 */
    char pad10[0x10];
    f32 scale_per_mille;            /* 0x20 */
    char pad24[0x14];
} ScalerMotion;

typedef struct {
    char pad00[0x10];
    EffectMotion motion;            /* 0x10 */
    void *owner;                    /* 0x48 */
    u16 frame;                      /* 0x4C */
    u16 effect_param;               /* 0x4E */
    ModelInstance *model;           /* 0x50 */
    EffectDef *def;                 /* 0x54 */
    char pad58[0x04];
    int effect_arg;                 /* 0x5C */
} EffectActor;

#endif
