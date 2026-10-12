#include "common.h"
#include <libdev_internal.h>

s32 func_0022B9E8(void);

/* Copies VIF1's registers into regs when VIF1 is stopped or idle. */
s32 func_0022BA38(DevVif1Regs *regs) {
    u32 cycle = *(volatile u32 *)VIF1_CYCLE;

    if ((u32)func_0022B9E8() >= 2) {
        return 0;
    }
    regs->row[0] = *(volatile u32 *)VIF1_R0;
    regs->row[1] = *(volatile u32 *)VIF1_R1;
    regs->row[2] = *(volatile u32 *)VIF1_R2;
    regs->row[3] = *(volatile u32 *)VIF1_R3;
    regs->col[0] = *(volatile u32 *)VIF1_C0;
    regs->col[1] = *(volatile u32 *)VIF1_C1;
    regs->col[2] = *(volatile u32 *)VIF1_C2;
    regs->col[3] = *(volatile u32 *)VIF1_C3;
    regs->mask = *(volatile u32 *)VIF1_MASK;
    regs->code = *(volatile u32 *)VIF1_CODE;
    regs->stat = *(volatile u32 *)VIF1_STAT;
    regs->itop = *(volatile u32 *)VIF1_ITOP;
    regs->itops = *(volatile u32 *)VIF1_ITOPS;
    regs->base = *(volatile u32 *)VIF1_BASE;
    regs->ofst = *(volatile u32 *)VIF1_OFST;
    regs->top = *(volatile u32 *)VIF1_TOP;
    regs->tops = *(volatile u32 *)VIF1_TOPS;
    regs->mark = *(volatile u32 *)VIF1_MARK;
    regs->num = *(volatile u32 *)VIF1_NUM;
    regs->err = *(volatile u32 *)VIF1_ERR;
    regs->cycle_cl = cycle;
    regs->cycle_wl = cycle >> 8;
    regs->mode = *(volatile u32 *)VIF1_MODE;
    return 1;
}
