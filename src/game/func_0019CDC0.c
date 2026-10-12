#include "common.h"

extern u8 D_00349682[];
extern int D_003EF5F8[];

void func_001CE690(int, int, int, char, int, char, s16, int);

/* Plays menu sound `sound` on voice 1 unless it is 0xFF (none). */
s32 func_0019CDC0(s32 sound) {
    if (sound != 0xFF) {
        func_001CE690(1, D_003EF5F8[0], 0, (char)sound, 0x3C, D_00349682[0], 0, 0x3F);
    }
    /* match: no return; an s32 function, so $2 stays live and the beq delay slot takes the second lui */
}
