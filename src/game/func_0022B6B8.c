#include "common.h"
#include <eeregs.h>

s32 func_0022B6B8(void) {
    s32 vif_stat;

    vif_stat = *VIF0_STAT;
    if (!(vif_stat & 3)) {
        return 0;
    }
    if (vif_stat & 0x700) {
        return 1;
    }
    if (vif_stat & 0xC) {
        return 2;
    }
    return (vif_stat & 0x3000) ? 3 : 4;
}
