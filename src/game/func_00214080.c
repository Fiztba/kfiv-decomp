#include "common.h"

typedef struct {
    char pad[0x7C];
    char *act;
} Actor;

void *func_00116160(int, int);
float func_0019B838(float);
extern int D_00446770;

/* Step the target actor's x/y/z position by this command's per-frame deltas, ending the command when its step count runs out. */
void func_00214080(char *command) {
    Actor *actor;
    int steps_left;

    actor = func_00116160(D_00446770, *(int *)(command + 0x8));
    if (actor == NULL || *(int *)(command + 0x28) <= 0) {
        *(int *)command = 0;
        return;
    }
    *(float *)(actor->act + 0xD0) = func_0019B838(*(float *)(actor->act + 0xD0) + *(float *)(command + 0x10));
    *(float *)(actor->act + 0xD4) = func_0019B838(*(float *)(actor->act + 0xD4) + *(float *)(command + 0x18));
    *(float *)(actor->act + 0xD8) = func_0019B838(*(float *)(actor->act + 0xD8) + *(float *)(command + 0x20));
    steps_left = *(int *)(command + 0x28) - 1;
    *(int *)(command + 0x28) = steps_left;
    if (steps_left < 0) {
        *(int *)command = 0;
    }
}
