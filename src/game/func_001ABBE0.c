#include "common.h"

void func_001AF928(char *, int);
void func_001AF640(void *, int);

void func_001ABBE0(char *actor, int frame) {
    char *state;

    state = actor + 0x10;
    func_001AF928(actor, frame);
    func_001AF640(actor, frame);
    *(char *)(state + 0x1C) = 0;
    *(s64 *)(actor + 0x40) |= 0x8000L << 43;
}
