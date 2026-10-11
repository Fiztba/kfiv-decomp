#include "common.h"

void *func_001267B0(int);

/* Move the looked-up object to the command's x/y/z, then clear the command. */
void func_00216580(char *command) {
    char *object;

    object = func_001267B0(*(int *)(command + 0x8));
    if (object != NULL) {
        *(float *)(*(char **)object + 0xC0) = *(float *)(command + 0x10);
        *(float *)(*(char **)object + 0xC4) = *(float *)(command + 0x18);
        *(float *)(*(char **)object + 0xC8) = *(float *)(command + 0x20);
    }
    *(int *)command = 0;
}
