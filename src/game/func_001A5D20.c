#include "common.h"

void func_001AF928(char *, int);
void func_001AF640(void *, int);
void func_001AF538(float *, float *, float);
s16 func_001B0208(float, void *, void *, void *);

/* Per-frame update for an actor: refresh the sub-state at +0x10 and reset its counters. */
void func_001A5D20(char *actor, int frame) {
    char *state;

    state = actor + 0x10;
    func_001AF928(actor, frame);
    func_001AF640(actor, frame);
    func_001AF538(state, (float *)(*(char **)(actor + 0x50) + 0xD0), *(float *)(*(char **)(actor + 0x54) + 0xD8));
    *(s16 *)(state + 0x20) = func_001B0208(30.0f, actor, state, actor + 0x20);
    *(char *)(state + 0x25) = 0;
    *(s16 *)(state + 0x22) = 0;
    *(char *)(state + 0x24) = 0;
}
