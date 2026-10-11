#include "common.h"

typedef struct {
    char pad[0x7C];
    char *model;
} Actor;

void *func_00116160(int, int);
int func_00211D90(void *, double);  // match: retail converts the float argument to double at the call site (fptodp), as the definition takes float
extern int D_00446770;

/* Feed the target actor's x/y/z position to three func_00211D90 commands, then clear the command. */
void func_00214130(char *command) {
    Actor *actor;

    actor = func_00116160(D_00446770, *(int *)(command + 0x8));
    if (actor != NULL) {
        func_00211D90(command + 0xC, *(float *)(actor->model + 0xC0));
        func_00211D90(command + 0x14, *(float *)(actor->model + 0xC4));
        func_00211D90(command + 0x1C, *(float *)(actor->model + 0xC8));
    }
    *(int *)command = 0;
}
