#include "common.h"

typedef struct {
    char pad[0xC0];
    float x;
    float y;
    float z;
} Pos;

typedef struct {
    Pos *pos;
} Rec;

extern unsigned char D_00349690[];
void func_0011E0C8(Rec *);
void func_0011E140(Rec *);
Rec *func_0011E1F0(int, int);
void func_001C8C80(int, int);

/* Parks or reveals the pair of scene records 0x66/0x67 depending on the stage flags. */
void func_0011A138(int arg0) {
    Rec *rec;

    if (D_00349690[0xA85] != 0) {
        if (D_00349690[0xA86] == 0) {
            func_001C8C80(arg0, 0xC9);
            rec = func_0011E1F0(arg0, 0x67);
            if (rec != NULL) {
                func_0011E0C8(rec);
                rec->pos->x = -19150.0f;
                rec->pos->y = -2030.0f;
                rec->pos->z = 3450.0f;
            }
        }
    } else {
        rec = func_0011E1F0(arg0, 0x66);
        if (rec != NULL) {
            func_0011E140(rec);
        }
        rec = func_0011E1F0(arg0, 0x67);
        if (rec != NULL) {
            func_0011E140(rec);
        }
    }
}
