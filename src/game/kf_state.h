/* Mode handlers: the context a per-mode handler table call receives, and the mode state record. */
#ifndef KF_STATE_H
#define KF_STATE_H

#include "common.h"

/* D_005CF340, D_005CF350: passed to the handler picked from a mode table */
typedef struct {
    int unk00;                      /* 0x00 */
    int unk04;                      /* 0x04 */
    int arg;                        /* 0x08 */
} HandlerContext;

/* D_005CF3F0, D_005CF410: a mode record and its sub-state (0x20 bytes apart) */
typedef struct {
    s32 slot;                       /* 0x00 index into D_00428B80 */
    char pad04[0x0C];
    s16 state;                      /* 0x10 selects the mode handler, 0: idle */
    u16 unk12;                      /* 0x12 */
    char unk14;                     /* 0x14 */
    char unk15;                     /* 0x15 */
    s8 phase;                       /* 0x16 */
    s8 count;                       /* 0x17 */
    u8 unk18;                       /* 0x18 */
    char pad19[0x02];
    s8 unk1B;                       /* 0x1B */
} ModeState;

/* D_00428B80: the 0x28-byte entries of the slot table, indexed by the mode slot */
typedef struct {
    char unk00;                     /* 0x00 */
    char unk01;                     /* 0x01 */
    char unk02;                     /* 0x02 */
    char unk03;                     /* 0x03 */
    char unk04;                     /* 0x04 */
    char unk05;                     /* 0x05 */
    char unk06;                     /* 0x06 */
    char unk07;                     /* 0x07 */
    char pad08[0x04];
    void *unk0C;                    /* 0x0C */
    void *unk10;                    /* 0x10 */
    void *unk14;                    /* 0x14 */
    s32 unk18;                      /* 0x18 */
    char pad1C[0x04];
    char unk20;                     /* 0x20 */
    char unk21;                     /* 0x21 */
    char pad22[0x02];
    s16 unk24;                      /* 0x24 */
    char pad26[0x02];
} SlotRecord;

extern SlotRecord D_00428B80[];

/* what the D_00440B70 handlers build; func_00207478 dispatches it by kind */
typedef struct {
    char pad00[0x31];
    u8 kind;                        /* 0x31 picks the function that consumes the object */
} KindObject;

/* a task that runs a one-time setup (func_00103858, func_001CF988) and ends when func_001CF980 reports done */
typedef struct {
    s32 active;                     /* 0x00 cleared once the setup is done */
    char pad04[0x04];
    s32 unk08;                      /* 0x08 */
    char pad0C[0x04];
    s32 unk10;                      /* 0x10 */
    char pad14[0x04];
    s32 unk18;                      /* 0x18 */
    char pad1C[0x68];
    s32 started;                    /* 0x84 set once the setup has been started */
} SetupTask;

#endif
