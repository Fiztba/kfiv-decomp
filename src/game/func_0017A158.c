#include "common.h"

void func_001958B8(char *, void (*)(void), int);
extern char D_0038CD20[];
extern int D_00446770;

/* Copy the actor position to its model, relative to the map origin when on another map. */
void func_0017A158(char *arg0, int arg1) {
    char *sub;
    char *out;
    char *map_entry;
    char *origin;
    float x;
    float y;
    float z;

    sub = arg0 + 0xE0;
    out = *(char **)arg0;
    x = *(float *)(sub + 0x48);
    *(float *)(out + 0xC0) = x;
    y = *(float *)(sub + 0x4C);
    *(float *)(out + 0xC4) = y;
    z = *(float *)(sub + 0x50);
    *(float *)(out + 0xC8) = z;
    if (*(char *)(arg0 + 0xD5) != D_00446770) {
        map_entry = D_0038CD20 + D_00446770 * 0x60;
        origin = *(char **)(map_entry + 0x1C) + *(s16 *)(*(char **)(arg0 + 0xC) + 0x43A) * 0x10;
        *(float *)(out + 0xC0) = x - *(float *)origin;
        *(float *)(out + 0xC4) = y - *(float *)(origin + 4);
        *(float *)(out + 0xC8) = z - *(float *)(origin + 8);
    }
    *(int *)(out + 0xD4) = 0;
    func_001958B8(arg0, *(void (**)(void))(sub + 0x18), arg1);
}
