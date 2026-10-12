#include "kf_entity.h"

void func_0019B2B0(void *);
void func_0019B290(void *);

/* Runs the two node helpers on entry index of the table (0x40-byte entries, 0x200 of them). */
void func_0019AA50(u32 index) {
    LinkedPoint *node;

    if (index < LINKED_POINT_COUNT) {
        node = &D_003E7500[index];
        func_0019B2B0(node);
        func_0019B290(node);
    }
}
