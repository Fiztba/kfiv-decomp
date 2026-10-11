#include "common.h"

typedef struct {
    char pad00[0x252];
    u16 map_index;
} State;

typedef struct {
    char pad00[0x14];
    char *entries;
    char pad18[0x48];
} MapRow;

extern int D_0038A130[0x28 / 4];
extern MapRow D_0038CD20[];
extern int D_00446770;
extern State D_00413F80;
extern s8 D_004470E3;

int func_001CBAE0(int, int, int, int);

/* Syncs the cached byte D_004470E3 to the current map row's value and sends it to the sound call. */
int func_001A14D8(void) {
    MapRow *row;
    int cur;
    int want;

    if (D_0038A130[3] == 0 && D_0038A130[6] == 0 && D_0038A130[1] == 0) {
        row = &D_0038CD20[D_00446770];
        cur = D_004470E3;
        if ((u8)row->entries[(D_00413F80.map_index << 7) + 0x4D] != cur) {
            if (cur >= 0x40) {
                D_004470E3 = 0x3F;
            } else if (cur < 0) {
                D_004470E3 = 0;
            }
            want = (u8)row->entries[(D_00413F80.map_index << 7) + 0x4D];
            D_004470E3 = want;
            func_001CBAE0(1, 0xD0, 0xB81, (s8)want << 8);
            return func_001CBAE0(1, 0xD0, 0xC81, D_004470E3 << 8);
        }
    }
}
