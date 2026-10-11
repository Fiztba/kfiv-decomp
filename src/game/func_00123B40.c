#include "common.h"

typedef struct {
    union { unsigned int w; struct { unsigned char a; unsigned short b; } f; } u;
    short c; unsigned char d; int e; int f;
} Entry;
extern Entry D_003D6DF0[];

/* Claims the first free pool block, else the unused block with the lowest size; returns its index. */
int func_00123B40(void) {
    int i;
    int best;
    Entry *p;

    best = -1;
    for (i = 0; i < 5; i++) {
        p = &D_003D6DF0[i];
        if ((p->u.w >> 9) & 1) { continue; }
        if ((p->u.w >> 8) & 1) { continue; }
        if (p->u.f.a == 0) { return i; }
        if (p->u.f.a != 4) { continue; }
        if (p->c != 0) { continue; }
        if (p->d != 0) { continue; }
        if (best == -1 || (unsigned int)p->e < (unsigned int)D_003D6DF0[best].e) {
            best = i;
        }
    }
    if (best >= 0) {
        D_003D6DF0[best].u.f.a = 0;
        if ((i = best + 1) < 5 && D_003D6DF0[i].u.f.a == 5) {
            D_003D6DF0[i].u.f.a = 0;
        }
    }
    return best;
}
