#include "common.h"

typedef struct {
    char b0;
    char b1;
    char b2;
    char pad[0x40 - 3];
} Entry;

extern Entry D_0034B6D0[];

void func_00190A30(char *);
void func_0019A310(char *, void (*)(void), int);
void func_00184778(void);

typedef struct {
    char pad0[0xC];
    char *controller;
    char pad1[0x4C];
    int unk5C;
    char pad2[0xD8 - 0x60];
    u64 flags;
} Actor;

void func_00185300(char *actor_ptr) {
    Actor *actor = (Actor *)actor_ptr;

    func_00190A30(actor_ptr);
    actor->unk5C = 0;
    actor->flags &= ~0x400;
    actor->flags &= ~0x200;
    func_0019A310(actor_ptr, func_00184778, 0);
    D_0034B6D0[*(s16 *)(actor->controller + 0x43A)].b2 = 1;
    if ((actor->flags >> 38) & 3) {
        actor->flags |= 0x20000000;
    }
}
