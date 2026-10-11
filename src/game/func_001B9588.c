#include "common.h"

extern char D_00413F80[];

typedef struct {
    char pad00[0x30];
    s16 clear_flag0;                /* 0x30 */
    s16 clear_flag1;                /* 0x32 */
    s16 clear_flag2;                /* 0x34 */
    s16 clear_flag3;                /* 0x36 */
    s16 clear_flag4;                /* 0x38 */
    s16 clear_flag5;                /* 0x3A */
    char pad3C[0x27C];
    u16 timer0;                     /* 0x2B8 */
    u16 timer1;                     /* 0x2BA */
    u16 timer2;                     /* 0x2BC */
    u16 timer3;                     /* 0x2BE */
    u16 timer4;                     /* 0x2C0 */
    u16 timer5;                     /* 0x2C2 */
} CountdownTable;

/* Counts six countdown timers down to zero, clearing each matching flag on the way. */
void func_001B9588(void) {
    CountdownTable *t = (CountdownTable *)D_00413F80;

    if (t->timer0 != 0) {
        t->clear_flag0 = 0;
        t->timer0--;
    }
    if (t->timer1 != 0) {
        t->clear_flag1 = 0;
        t->timer1--;
    }
    if (t->timer2 != 0) {
        t->clear_flag2 = 0;
        t->timer2--;
    }
    if (t->timer3 != 0) {
        t->clear_flag3 = 0;
        t->timer3--;
    }
    if (t->timer4 != 0) {
        t->clear_flag4 = 0;
        t->timer4--;
    }
    if (t->timer5 != 0) {
        t->clear_flag5 = 0;
        t->timer5--;
    }
}
