#include "common.h"

int func_001CBAE0();
extern char *D_004471D4;

typedef struct {
    u32 f0 : 5;
    u32 f5 : 1;
    u32 f6 : 7;
    u32 f13 : 3;
    u32 f16 : 4;
    u32 f20 : 4;
    u32 f24 : 7;
    u32 f31 : 1;
} Packed;

/* Sends slot arg0's two words with arg1; the reply is re-packed into *arg2 (some fields inverted). */
void func_001CF1F0(int arg0, int arg1, Packed *arg2) {
    char *slot;
    u32 v, w;

    slot = D_004471D4 + (arg0 << 5);
    v = func_001CBAE0(1, 0x110, *(int *)slot, *(int *)(slot + 0x10), arg1);
    w = ~v;
    arg2->f31 = v >> 31;
    arg2->f24 = w >> 24;
    arg2->f20 = w >> 20;
    arg2->f16 = v >> 16;
    arg2->f13 = v >> 13;
    arg2->f6 = w >> 6;
    arg2->f5 = v >> 5;
    arg2->f0 = w;
}
