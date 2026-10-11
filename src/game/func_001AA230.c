#include "common.h"

void func_001AF928(char *, int);
void func_001AF640(void *, int);
int func_001A2838(int, void *);

void func_001AA230(char *actor, int arg1) {
    char *state;
    char *ctl;

    state = actor + 0x10;
    func_001AF928(actor, arg1);
    func_001AF640(actor, arg1);
    ctl = *(char **)(actor + 0x54);
    *(u16 *)(actor + 0x10) = *(u16 *)(ctl + 0xEC);
    *(u16 *)(state + 2) = *(u16 *)(ctl + 0xEE);
    if (*(u16 *)(ctl + 0xF0) != 0) {
        func_001A2838(*(u16 *)(ctl + 0xF0), actor);
    }
    if (*(u16 *)(*(char **)(actor + 0x54) + 0xF2) != 0) {
        func_001A2838(*(u16 *)(*(char **)(actor + 0x54) + 0xF2), actor);
    }
}
