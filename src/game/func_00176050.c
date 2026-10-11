#include "common.h"

void func_001760B8(void *, int);
void func_00176238(void *, int);

void func_00176050(char *actor, int arg1) {
    if (*(u16 *)(actor + 0xC6) != 0) {
        return;
    }
    if (*(float *)(actor + 0x64) < (float) *(s16 *)(*(char **)(actor + 0xC) + 0x430)) {
        if (*(s8 *)(actor + 0xCC) != 3) {
            *(s8 *)(actor + 0xCC) = 3;
        }
    }
    if (*(s8 *)(actor + 0xCC) == 3) {
        func_00176238(actor, arg1);
        return;
    }
    func_001760B8(actor, arg1);
}
