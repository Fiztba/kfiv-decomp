#include "common.h"

/* Copies out a texture's TEX0 word and, for a palettized PSM, the word after its CLUT. */

typedef struct {
    int unk0;
    int image_size;
    char pad8[0x10 - 0x8];
    u64 tex0;
    char pad18[0x20 - 0x18];
} TexHeader;

void func_00204D60(TexHeader *tex, u64 *tex0_out, u64 *trailer_out) {
    char buf[0xC0]; /* unused, but retail reserves the 0xC0 bytes */
    u64 *trailer;
    int psm;
    int clut_w;
    int clut_h;

    if (tex0_out != NULL) {
        *tex0_out = tex->tex0;
    }
    psm = (int)((tex->tex0 >> 20) & 0x3F);
    if ((psm >> 4) == 0 || (psm >> 4) == 3) {
        return;
    }
    clut_w = (psm & 4) ? 8 : 16;
    clut_h = (psm & 4) ? 2 : 16;
    trailer = (u64 *)((char *)tex + (clut_w * clut_h) * 4 + (tex->image_size + 0x20));
    if (trailer_out != NULL) {
        *trailer_out = *trailer;
    }
}
