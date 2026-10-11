#include "common.h"

typedef struct {
    char unk0[0x12];
    unsigned char level;
    unsigned char exp;
    char unk14[0xE];
} Rec22;

typedef struct {
    char unk0[0x37];
    unsigned char exp_per_level;
    char unk38[8];
} Def40;

extern Rec22 D_003682F0[];
extern Def40 D_00417EF8[];

/* Adds experience to a record, rolling over into levels (levels below 0x33 reset to 0x32). */
void func_001B4DF8(int idx, int amount) {
    Rec22 *rec = &D_003682F0[idx];
    Def40 *def = &D_00417EF8[idx];

    if (rec->level >= 0x33 && idx != 0 && idx != 0x1E && idx != 0x37 && idx != 0x50 && idx != 0x69 &&
        idx != 0x82 && idx != 0x8C && idx != 0x96) {
        rec->exp += amount;
        while (rec->exp >= def->exp_per_level) {
            rec->exp -= def->exp_per_level;
            rec->level--;
            if (rec->level < 0x33) {
                rec->level = 0x32;
                rec->exp = 0;
                break;
            }
        }
    }
}
