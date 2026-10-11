#include "common.h"

typedef struct {
    char pad0[0x108];
    u16 max_frames;     /* 0 means no limit */
    char pad1[0xE];
    u16 end_effect;
} Ctl;

typedef struct {
    char pad0[0x10];
    u16 end_frame;
} Sub;

typedef struct {
    char pad0[0x10];
    Sub sub;
    char pad1[0x48 - 0x22];
    void *owner;
    u16 frame;
    u16 effect_param;
    char *target;
    Ctl *ctl;
    char pad2[4];
    int effect_arg;
} Actor;

void func_001AEC48(void *);
void func_001AED58(void *);
void func_001AF0B0(void *);
int func_001B4F90(void *);
int func_001A2A18(void *);
void func_001A1E28(u16, void *, void *, int, u16, void *);
void sceVu0AddVector(void *, void *, void *);

void func_001A4CE8(Actor *actor) {
    char *velocity;
    char *target;

    func_001AEC48(actor);
    velocity = (char *)actor + 0x10;
    func_001AED58(actor);
    func_001AF0B0(actor);
    if (actor->frame < actor->ctl->max_frames || actor->ctl->max_frames == 0) {
        sceVu0AddVector(actor->target + 0xC0, actor->target + 0xC0, velocity);
    }
    if (func_001B4F90(actor) != 0 || *(u16 *)(velocity + 0x10) == actor->frame) {
        target = actor->target;
        func_001A1E28(actor->ctl->end_effect, target + 0xC0, target + 0xD0, actor->effect_arg, actor->effect_param, actor->owner);
        func_001A2A18(actor);
    }
    actor->frame = actor->frame + 1;
}
