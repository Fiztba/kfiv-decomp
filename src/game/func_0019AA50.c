#include "common.h"

void func_0019B2B0(void *);
void func_0019B290(void *);
extern char D_003E7500[];

/* Runs the two node helpers on entry index of the table (0x40-byte entries, 0x200 of them). */
void func_0019AA50(u32 index) {
    void *node;

    if (index < 0x200) {
        node = D_003E7500 + (index << 6);
        func_0019B2B0(node);
        func_0019B290(node);
    }
}
