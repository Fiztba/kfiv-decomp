#include "common.h"
#include "kf_model.h"
#include <libdev_internal.h>

s32 func_0022B060(void);
void func_0022B090(u16 vi_addr, Qword *src);

/* Writes ctx's registers back into VU0's memory window when VU0 is idle. */
s32 func_0022B470(DevVu0MemCtx *ctx) {
    DevVu0Quad buf;
    u32 i;

    if (func_0022B060()) {
        return 0;
    }
    for (i = 0; i < 32; i++) {
        buf.whole = ctx->vector_regs[i];
        func_0022B090((u16)(i + 0x400), (Qword *)&buf.parts);
    }
    buf.whole = 0;
    buf.parts.unk00 = ctx->ctrl_regs[0];
    func_0022B090(0x430, (Qword *)&buf.parts);
    buf.parts.unk00 = ctx->ctrl_regs[1];
    func_0022B090(0x431, (Qword *)&buf.parts);
    buf.parts.unk00 = ctx->ctrl_regs[2];
    func_0022B090(0x432, (Qword *)&buf.parts);
    buf.parts.unk00 = ctx->ctrl_regs[3];
    func_0022B090(0x434, (Qword *)&buf.parts);
    buf.parts.unk00 = ctx->ctrl_regs[4];
    func_0022B090(0x435, (Qword *)&buf.parts);
    buf.parts.unk00 = ctx->ctrl_regs[5];
    func_0022B090(0x436, (Qword *)&buf.parts);
    buf.parts.unk00 = ctx->ctrl_regs[6];
    func_0022B090(0x437, (Qword *)&buf.parts);
    for (i = 0; i < 16; i++) {
        buf.parts.unk00 = ctx->int_regs[i];
        func_0022B090((u16)(i + 0x420), (Qword *)&buf.parts);
    }
    return 1;
}
