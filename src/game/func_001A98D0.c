#include "common.h"

typedef struct {
    char pad0[0xEC];
    u16 radius_half;
    u16 interval;
    char pad1[0x18];
    u16 max_frames;     /* 0 means no limit */
} Ctl;

typedef struct {
    char pad0[0x14];
    int countdown;
} Sub;

typedef struct {
    char pad0[0x10];
    Sub sub;
    char pad1[0x24];
    u16 frame;
    u16 unk4E;
    char *target;
    Ctl *ctl;
} Actor;

extern int D_004468E0;
void func_001AEC48(void *);
void func_001AED58(void *);
void func_001AF0B0(void *);
void func_001AF298(void *, void *);
void func_001A2A18(void *);
int func_001C0E40(float, void *);
void sceVu0AddVector(void *, void *, void *);

void func_001A98D0(Actor *actor) {
    char *velocity;
    int countdown;
    u16 interval;

    D_004468E0 = 0;
    func_001AEC48(actor);
    velocity = (char *)actor + 0x10;
    func_001AED58(actor);
    func_001AF0B0(actor);
    countdown = *(int *)(velocity + 0x14);
    if (countdown <= 0) {
        if (actor->frame < actor->ctl->max_frames || actor->ctl->max_frames == 0) {
            sceVu0AddVector(actor->target + 0xC0, actor->target + 0xC0, velocity);
            if (func_001C0E40(actor->ctl->radius_half * 2, actor->target + 0xC0) == 0) {
                func_001A2A18(actor);
                return;
            }
            *(float *)(actor->target + 0xC4) = *(float *)0x70000004;
        }
        interval = actor->ctl->interval;
        *(int *)(velocity + 0x14) = interval;
        countdown = interval;
    }
    *(int *)(velocity + 0x14) = countdown - 1;
    if (actor->frame >= 0x15) {
        func_001AF298(actor, velocity + 0x18);
    }
    actor->frame = actor->frame + 1;
}
