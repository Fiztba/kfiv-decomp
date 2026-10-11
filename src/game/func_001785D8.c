#include "common.h"

int func_00192C98(void *, int, int, u32, int);

typedef struct {
    char pad0[0x10];
    struct {
        char pad0[0x41];
        u8 variant;
    } *controller;
    char pad1[0xD8 - 0x14];
    s64 flags;
} Actor;

void func_001785D8(Actor *actor) {
    if (actor->controller->variant == 1) {
        func_00192C98(actor, 0x12, 0, 0, 0);
    } else {
        func_00192C98(actor, 0x13, 0, 0, 0);
    }
    actor->flags |= 0x40000;
    actor->flags |= 0x100000;
    actor->flags |= 0x200000;
    actor->flags |= 0x400000;
    actor->flags |= 0x800000;
    actor->flags |= 0x1000000;
    actor->flags |= 0x2000000;
    actor->flags |= 0x4000000;
    actor->flags |= 0x10000;
    actor->flags |= 0x10000000;
}
