#include "common.h"

void func_001AF928(char *, int);
void func_001AF640(void *, int);
void func_001AF538(float, void *, void *);
s16 func_001B0208(float, void *, void *, void *);

/* Per-frame update for an actor: sets the sub-state at +0x10 from its definition at +0x54. */
void func_001AA330(char *actor, int frame) {
    char *state;
    char *definition;
    s16 angle;

    state = actor + 0x10;
    func_001AF928(actor, frame);
    func_001AF640(actor, frame);
    func_001AF538(*(float *)(*(char **)(actor + 0x54) + 0xD8), state, *(char **)(actor + 0x50) + 0xD0);
    angle = func_001B0208((float)*(u16 *)(*(char **)(actor + 0x54) + 0xEC), actor, state, actor + 0x20);
    *(char *)(state + 0x24) = 0;
    *(s16 *)(state + 0x22) = angle;
    definition = *(char **)(actor + 0x54);
    *(u16 *)(state + 0x20) = *(u16 *)(definition + 0x118);
    if (*(u16 *)(definition + 0xF2) != 0) {
        *(s64 *)(actor + 0x40) |= (s64)0x8000 << 43;
    }
}
