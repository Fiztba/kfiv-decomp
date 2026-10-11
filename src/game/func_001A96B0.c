#include "common.h"

typedef struct {
    char pad0[0x104];
    float gravity;
} Ctl;

typedef struct {
    char pad0[4];
    float velocity_y;
    char pad1[8];
    int mode;
    u16 end_frame;
} Sub;

typedef struct {
    char pad0[0x10];
    Sub sub;
    char pad1[0x48 - 0x28];
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
int func_001AF0B0(void *);  // match: callee return value must be visible (int) for retail register allocation; other callers differ
void func_001AF298(void *, void *);
void sceVu0AddVector(void *, void *, void *);
void func_001A2A18(void *);
int func_001A1E28(int, int, int, int, u16, int);

void func_001A96B0(Actor *actor) {
    Sub *sub;
    func_001AEC48(actor);
    sub = &actor->sub;
    func_001AED58(actor);
    func_001AF0B0(actor);
    sub->velocity_y = sub->velocity_y + actor->ctl->gravity;
    sceVu0AddVector(actor->target + 0xC0, actor->target + 0xC0, sub);
    if (actor->frame > sub->end_frame) {
        if (sub->mode == 5 || sub->mode == 3) {
            func_001A1E28(0x15, (int)(actor->target + 0xC0), (int)(actor->target + 0xD0), actor->effect_arg, actor->effect_param, (int)actor->owner);
        }
        func_001A2A18(actor);
        return;
    }
    func_001AF298(actor, (char *)actor + 0x27);
    actor->frame++;
}
