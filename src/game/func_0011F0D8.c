#include "common.h"

extern int D_00446770;
void func_0019E9E0(char);

void func_0011F0D8(char *object) {
    char *source;

    if (*(u8 *)(*(char **)(object + 4)) == 0) {
        source = *(char **)(object + 8);
        if (((u32)(*(u16 *)(source + 0x44) - 0x40) < 0x40) && (*(int *)(object + 0x40) != 0)) {
            if ((*(u8 *)(object + 0x10) & 1) != D_00446770) {
                *(int *)(object + 0x40) = 0;
                return;
            }
            func_0019E9E0(*(char *)(source + 0x44));
            *(int *)(object + 0x40) = 0;
        }
    }
}
