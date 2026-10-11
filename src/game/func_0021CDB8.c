#include "common.h"

#define HW_1000B400 (*(volatile u32 *)0x1000B400)
#define HW_1000F520 (*(volatile u32 *)0x1000F520)
#define HW_1000F590 (*(volatile u32 *)0x1000F590)

int DIntr(void);
int EIntr(void);

void func_0021CDB8(int value) {
    DIntr();
    HW_1000F590 = HW_1000F520 | 0x10000;
    HW_1000B400 = value;
    HW_1000F590 = HW_1000F520 & 0xFFFEFFFF;
    EIntr();
}
