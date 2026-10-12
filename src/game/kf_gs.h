/* GS registers, as passed to func_00109A80 (set a GS register). */
#ifndef KF_GS_H
#define KF_GS_H

#include "common.h"

#define GS_REG_TEX0_1       0x06
#define GS_REG_TEX1_1       0x14
#define GS_REG_XYOFFSET_1   0x18
#define GS_REG_XYOFFSET_2   0x19
#define GS_REG_SCANMSK      0x22
#define GS_REG_TEXFLUSH     0x3F
#define GS_REG_SCISSOR_1    0x40
#define GS_REG_SCISSOR_2    0x41
#define GS_REG_ALPHA_1      0x42
#define GS_REG_ALPHA_2      0x43
#define GS_REG_TEST_1       0x47
#define GS_REG_TEST_2       0x48
#define GS_REG_FRAME_1      0x4C
#define GS_REG_FRAME_2      0x4D
#define GS_REG_ZBUF_1       0x4E
#define GS_REG_ZBUF_2       0x4F
#define GS_REG_FINISH       0x61

/* a color as four bytes, passed in an 8-byte argument (func_001FDCD0 stores it to D_00446D70..D_00446D73) */
typedef struct {
    u8 red;                         /* 0x00 */
    u8 green;                       /* 0x01 */
    u8 blue;                        /* 0x02 */
    u8 alpha;                       /* 0x03 */
    char pad04[0x04];
} ColorBytes;

/* the ALPHA registers (GS_REG_ALPHA_1/2) as a value to write */
typedef union {
    s64 raw;
    struct {
        u64 a_source : 2;           /* 0 */
        u64 b_source : 2;           /* 2 */
        u64 c_source : 2;           /* 4 */
        u64 d_source : 2;           /* 6 */
        u64 pad8 : 24;
        u64 fix : 8;                /* 32 */
        u64 pad40 : 24;
    } f;
} GsAlphaReg;

/* a 64-bit value split into 16, 16, 24 and 8 bits, passed to func_001FDB88 and kept
   in D_00446D60; `raw` is the same word whole */
typedef union {
    s64 raw;
    struct {
        u64 lo16 : 16;              /* 0 */
        u64 mid16 : 16;             /* 16 */
        u64 mid24 : 24;             /* 32 */
        u64 hi8 : 8;                /* 56 */
    } f;
} GsPackedWord;

int func_001FDB88(GsPackedWord);

/* the rectangle func_001FC5E8 draws: two corners, a color and a scale */
typedef struct {
    GsPackedWord first;             /* 0x00 */
    char pad08[0x08];
    GsPackedWord second;            /* 0x10 */
    char pad18[0x08];
    u8 red;                         /* 0x20 */
    u8 green;                       /* 0x21 */
    u8 blue;                        /* 0x22 */
    u8 alpha;                       /* 0x23 */
    f32 scale;                      /* 0x24 */
} RectDef;

#endif
