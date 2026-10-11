#include "common.h"

void *func_001267B0(int);
void func_001C8CB0(void *);

/* Run func_001C8CB0 on the looked-up object with its +0x38 field temporarily set, then clear the command. */
void func_00212690(char *command) {
    u16 saved_value;
    char *object;
    char *inner;

    object = func_001267B0(*(int *)(command + 0x10));
    if (object != NULL) {
        inner = *(char **)(object + 0x10);
        saved_value = *(u16 *)(inner + 0x38);
        *(u16 *)(inner + 0x38) = *(u16 *)(command + 0x8);
        func_001C8CB0(object);
        inner = *(char **)(object + 0x10);
        *(u16 *)(inner + 0x38) = saved_value;
    }
    *(int *)command = 0;
}
