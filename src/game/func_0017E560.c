#include "common.h"

typedef struct {
    char pad0[0xC];
    unsigned char *ctl;
    char pad1[0xD8 - 0x10];
    unsigned long long bits;
} Actor;

int func_0019A448(void *, void *, int, int, int, int, int);

void func_0017E560(char *arg0) {
    Actor *a = (Actor *)arg0;

    a->bits &= ~0x3800ULL;
    func_0019A448(arg0, arg0 + 0x160, 0, 3, 5, a->ctl[0xC4], 0);
    func_0019A448(arg0, arg0 + 0x168, 1, 3, 5, a->ctl[0xC4], 0);
}
