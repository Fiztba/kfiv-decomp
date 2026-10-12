#include "kf_gs.h"

extern u8 D_00446D70;
extern u8 D_00446D71;
extern u8 D_00446D72;
extern u8 D_00446D73;

s32 func_001FDCD0(ColorBytes bytes) {
    D_00446D70 = bytes.red;
    D_00446D71 = bytes.green;
    D_00446D72 = bytes.blue;
    D_00446D73 = bytes.alpha;
    return 1;
}
