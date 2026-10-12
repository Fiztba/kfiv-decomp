#include "common.h"
#include <libdev_internal.h>
s32 func_0022B060(void);

/* Reads VU0's registers out of its memory window into ctx when VU0 is idle. */
s32 func_0022B2E0(DevVu0MemCtx *ctx) {
    DevVu0Quad buf[8];
    u32 i;

    if (func_0022B060()) {
        return 0;
    }
    for (i = 0; i < 32; i++) {
        sceDevVu0GetMem(&buf[0], (u16)(i + 0x400));
        ctx->vector_regs[i] = buf[0].whole;
    }
    sceDevVu0GetMem(&buf[0], 0x430);
    ctx->ctrl_regs[0] = buf[0].words[0];
    sceDevVu0GetMem(&buf[1], 0x431);
    ctx->ctrl_regs[1] = buf[1].words[0];
    sceDevVu0GetMem(&buf[2], 0x432);
    ctx->ctrl_regs[2] = buf[2].words[0];
    sceDevVu0GetMem(&buf[3], 0x434);
    ctx->ctrl_regs[3] = buf[3].words[0];
    sceDevVu0GetMem(&buf[4], 0x435);
    ctx->ctrl_regs[4] = buf[4].words[0];
    sceDevVu0GetMem(&buf[5], 0x436);
    ctx->ctrl_regs[5] = buf[5].words[0];
    sceDevVu0GetMem(&buf[6], 0x437);
    ctx->ctrl_regs[6] = buf[6].words[0];
    for (i = 0; i < 16; i++) {
        sceDevVu0GetMem(&buf[7], (u16)(i + 0x420));
        ctx->int_regs[i] = buf[7].halves[0];
    }
    return 1;
}
