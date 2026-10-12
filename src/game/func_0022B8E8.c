#include "common.h"
#include <eeregs.h>

void func_0022B8E8(void) {
    *VIF1_FBRST = 1;
    *VIF1_ERR = 6;
}
