#include "common.h"

typedef struct {
    char pad0[3];
    signed char a3;
    unsigned char a4;
} TblA;

extern TblA D_0038CC50[];
extern float D_004325A0[];

typedef struct {
    int unk00;
    char pad04[4];
    int unk08;
    char pad0C[4];
    float unk10;
    char pad14[4];
    float unk18;
    char pad1C[4];
    float unk20;
} Ctl;

void func_00213A60(Ctl *arg0) {
    if (D_0038CC50->a3) {
        if (arg0->unk08 >= 0) {
            if (arg0->unk08 < 2) {
                D_0038CC50->a4 = arg0->unk08;
                D_004325A0[8] = arg0->unk10;
                D_004325A0[9] = arg0->unk18;
                D_004325A0[10] = arg0->unk20;
            }
        }
    }
    arg0->unk00 = 0;
}
