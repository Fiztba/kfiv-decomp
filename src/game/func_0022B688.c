#include "common.h"
#include <eeregs.h>

s32 func_0022B688(s32 flag_a, s32 flag_b, s32 flag_c) {
    s32 value;

    value = flag_a | (flag_b << 1) | (flag_c << 2);
    *VIF0_ERR = value;
    return value;
}
