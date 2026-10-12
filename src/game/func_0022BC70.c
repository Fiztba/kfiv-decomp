#include "common.h"
#include <eeregs.h>
#include "kf_model.h"

s32 func_0022BC70(Uint128 *dst, s32 count) {
    Uint128 *cursor;
    Uint128 value;
    s32 received;
    s32 remaining;

    received = 0;
    remaining = count - 1;
    if (count != 0) {
        cursor = dst;
        do {
            if (!(*VIF1_STAT & 0x1F000000)) {
                return received;
            }
            value = *(volatile Uint128 *)VIF1_FIFO;
            received++;
            remaining--;
            *cursor = value;
            cursor++;
        } while (remaining != -1);
    }
    return received;
}
