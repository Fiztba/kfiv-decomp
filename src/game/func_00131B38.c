#include "common.h"

extern int D_00413F80[];
s16 func_00190F90(float, char *, int);
void func_001958B8(char *, void (*)(void), int);

typedef struct {
    char pad0[0x5C];
    int *p5C;
    char pad60[0xC8 - 0x60];
    s16 sC8;
    char padCA[0xD8 - 0xCA];
    u64 b0 : 9;
    u64 b9 : 1;
    u64 b10 : 1;
    u64 b11 : 3;
    u64 b14 : 50;
} Actor;

void func_00131B38(char *arg0, int arg1) {
    Actor *a = (Actor *)arg0;
    char *sub = arg0 + 0xE0;

    a->p5C = D_00413F80;
    a->b11 = 1;
    a->b9 = 1;
    a->sC8 = func_00190F90(50.0f, arg0, 1);
    func_001958B8(arg0, *(void (**)(void))(sub + 0x18), arg1);
}
