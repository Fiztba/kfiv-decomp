#include "common.h"
#include "kf_model.h"
#include <libdev_internal.h>

/* Saves VU0's vector registers into ctx and reloads its integer registers if VU0 is not running. */
s32 func_0022AEF0(DevVu0Ctx *ctx) {
    s32 result;
    u32 reg;
    DevU128 *vector_base = ctx->vector_regs;

    if (sceDevVu0IsRunning()) {
        result = 0;
    } else {
        __asm__ volatile("sqc2 $vf0, 0x0(%0)" : : "r"(vector_base));
        __asm__ volatile("sqc2 $vf1, 0x10(%0)" : : "r"(vector_base));
        __asm__ volatile("sqc2 $vf2, 0x20(%0)" : : "r"(vector_base));
        __asm__ volatile("sqc2 $vf3, 0x30(%0)" : : "r"(vector_base));
        __asm__ volatile("sqc2 $vf4, 0x40(%0)" : : "r"(vector_base));
        __asm__ volatile("sqc2 $vf5, 0x50(%0)" : : "r"(vector_base));
        __asm__ volatile("sqc2 $vf6, 0x60(%0)" : : "r"(vector_base));
        __asm__ volatile("sqc2 $vf7, 0x70(%0)" : : "r"(vector_base));
        __asm__ volatile("sqc2 $vf8, 0x80(%0)" : : "r"(vector_base));
        __asm__ volatile("sqc2 $vf9, 0x90(%0)" : : "r"(vector_base));
        __asm__ volatile("sqc2 $vf10, 0xA0(%0)" : : "r"(vector_base));
        __asm__ volatile("sqc2 $vf11, 0xB0(%0)" : : "r"(vector_base));
        __asm__ volatile("sqc2 $vf12, 0xC0(%0)" : : "r"(vector_base));
        __asm__ volatile("sqc2 $vf13, 0xD0(%0)" : : "r"(vector_base));
        __asm__ volatile("sqc2 $vf14, 0xE0(%0)" : : "r"(vector_base));
        __asm__ volatile("sqc2 $vf15, 0xF0(%0)" : : "r"(vector_base));
        __asm__ volatile("sqc2 $vf16, 0x100(%0)" : : "r"(vector_base));
        __asm__ volatile("sqc2 $vf17, 0x110(%0)" : : "r"(vector_base));
        __asm__ volatile("sqc2 $vf18, 0x120(%0)" : : "r"(vector_base));
        __asm__ volatile("sqc2 $vf19, 0x130(%0)" : : "r"(vector_base));
        __asm__ volatile("sqc2 $vf20, 0x140(%0)" : : "r"(vector_base));
        __asm__ volatile("sqc2 $vf21, 0x150(%0)" : : "r"(vector_base));
        __asm__ volatile("sqc2 $vf22, 0x160(%0)" : : "r"(vector_base));
        __asm__ volatile("sqc2 $vf23, 0x170(%0)" : : "r"(vector_base));
        __asm__ volatile("sqc2 $vf24, 0x180(%0)" : : "r"(vector_base));
        __asm__ volatile("sqc2 $vf25, 0x190(%0)" : : "r"(vector_base));
        __asm__ volatile("sqc2 $vf26, 0x1A0(%0)" : : "r"(vector_base));
        __asm__ volatile("sqc2 $vf27, 0x1B0(%0)" : : "r"(vector_base));
        __asm__ volatile("sqc2 $vf28, 0x1C0(%0)" : : "r"(vector_base));
        __asm__ volatile("sqc2 $vf29, 0x1D0(%0)" : : "r"(vector_base));
        __asm__ volatile("sqc2 $vf30, 0x1E0(%0)" : : "r"(vector_base));
        __asm__ volatile("sqc2 $vf31, 0x1F0(%0)" : : "r"(vector_base));
        reg = ctx->ctrl_regs[0];
        LIBDEV_CTC2(reg, vi16);
        reg = ctx->ctrl_regs[1];
        LIBDEV_CTC2(reg, vi17);
        reg = ctx->ctrl_regs[2];
        LIBDEV_CTC2(reg, vi18);
        reg = ctx->ctrl_regs[3];
        LIBDEV_CTC2(reg, vi20);
        reg = ctx->ctrl_regs[4];
        LIBDEV_CTC2(reg, vi21);
        reg = ctx->ctrl_regs[5];
        LIBDEV_CTC2(reg, vi22);
        reg = ctx->int_regs[0];
        LIBDEV_CTC2(reg, vi0);
        reg = ctx->int_regs[1];
        LIBDEV_CTC2(reg, vi1);
        reg = ctx->int_regs[2];
        LIBDEV_CTC2(reg, vi2);
        reg = ctx->int_regs[3];
        LIBDEV_CTC2(reg, vi3);
        reg = ctx->int_regs[4];
        LIBDEV_CTC2(reg, vi4);
        reg = ctx->int_regs[5];
        LIBDEV_CTC2(reg, vi5);
        reg = ctx->int_regs[6];
        LIBDEV_CTC2(reg, vi6);
        reg = ctx->int_regs[7];
        LIBDEV_CTC2(reg, vi7);
        reg = ctx->int_regs[8];
        LIBDEV_CTC2(reg, vi8);
        reg = ctx->int_regs[9];
        LIBDEV_CTC2(reg, vi9);
        reg = ctx->int_regs[10];
        LIBDEV_CTC2(reg, vi10);
        reg = ctx->int_regs[11];
        LIBDEV_CTC2(reg, vi11);
        reg = ctx->int_regs[12];
        LIBDEV_CTC2(reg, vi12);
        reg = ctx->int_regs[13];
        LIBDEV_CTC2(reg, vi13);
        reg = ctx->int_regs[14];
        LIBDEV_CTC2(reg, vi14);
        reg = ctx->int_regs[15];
        LIBDEV_CTC2(reg, vi15);
        result = 1;
    }
    return result;
}
