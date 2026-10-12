#include "common.h"
#include "kf_state.h"

extern s16 D_005CF420[];

void func_001FBC60(void) {
    SLOT_RECORD_BYTES(&D_00428B80[0])->first = 1;
    D_005CF420[0] = 0;
    SLOT_RECORD_BYTES(&D_00428B80[1])->first = 1;
}
