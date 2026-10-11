#include "common.h"

typedef struct E {
    char pad[0x78];
    u64 addr : 32;
    u64 pad2 : 21;
    u64 count : 11;
} E;

typedef struct O {
    char pad[0xF0];
    u16 n;
    char pad2[6];
    E *e;
} O;

void func_0010E6A8(O *arg0, s64 arg1, s64 arg2) {
    E *e;
    char *a;
    char *base;
    int i;
    int j;
    int c;
    int n;
    u16 cnt;
    int t;
    int b;
    int m;

    b = arg2;
    b &= 0x7FF;
    b <<= 15;
    m = arg1;
    m &= 0x7FF;
    m <<= 15;
    e = arg0->e;
    n = arg0->n;
    for (i = 0; i < n; i++, e++) {
        c = e->count;
        a = (char *)(int)e->addr;
        for (j = 0; j < c; j++) {
            base = a;
            cnt = *(u16 *)base;
            a += 0x70;
            t = *(int *)(a + 4) & 0x03FF8000;
            *(int *)(a + 4) = (t & ~m) | b | (*(int *)(a + 4) & 0xFC007FFF);
            a = base + (cnt + 1) * 0x10;
        }
    }
}
