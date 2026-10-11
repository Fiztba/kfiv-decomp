#include "common.h"

extern char D_00413F80[];

void func_001AF928(void *, int);
void func_001AF640(void *, int);
void func_001AF538(float, void *, void *);
int func_001AFD08(void *, void *, void *);

void func_001AD278(char *actor, int frame) {
    float speed;
    char *state;
    char *definition;

    definition = *(char **)(actor + 0x60);
    state = actor + 0x10;
    func_001AF928(actor, frame);
    func_001AF640(actor, frame);
    *(int *)(actor + 0x6C) = func_001AFD08(actor, D_00413F80, D_00413F80 + 0x10);
    speed = *(float *)(definition + 0x10);
    *(float *)(state + 0x10) = speed;
    func_001AF538(speed, state, *(char **)(actor + 0x50) + 0xD0);
    *(int *)(state + 0x14) = 0;
    *(float *)(state + 0x18) = 1.0f;
    *(char *)(state + 0x20) = 0;
}
