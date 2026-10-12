#include "common.h"
#include <eeregs.h>
#include "kf_model.h"

s32 func_0022B888(Uint128 *src, s32 count) {
    Uint128 *cursor;
    Uint128 value;
    s32 sent;
    s32 remaining;

    sent = 0;
    remaining = count - 1;
    if (count != 0) {
        cursor = src;
        do {
            if (*VIF0_STAT & 0x10000000) {
                return sent;
            }
            value = *cursor;
            cursor++;
            sent++;
            remaining--;
            *(volatile Uint128 *)VIF0_FIFO = value;
        } while (remaining != -1);
    }
    return sent;
}
