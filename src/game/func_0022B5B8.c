#include "common.h"
#include <eeregs.h>

void func_0022B5B8(void) {
    *VIF0_FBRST = 1;
    *VIF0_ERR = 6;
}
