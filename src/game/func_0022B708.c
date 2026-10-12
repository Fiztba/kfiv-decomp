#include "common.h"
#include <libdev_internal.h>

s32 func_0022B6B8(void);

/* Copies VIF0's registers into regs when VIF0 is stopped or idle. */
s32 func_0022B708(DevVif0Regs *regs) {
    u32 cycle = *(volatile u32 *)VIF0_CYCLE;

    if ((u32)func_0022B6B8() >= 2) {
        return 0;
    }
    regs->row[0] = *(volatile u32 *)VIF0_R0;
    regs->row[1] = *(volatile u32 *)VIF0_R1;
    regs->row[2] = *(volatile u32 *)VIF0_R2;
    regs->row[3] = *(volatile u32 *)VIF0_R3;
    regs->col[0] = *(volatile u32 *)VIF0_C0;
    regs->col[1] = *(volatile u32 *)VIF0_C1;
    regs->col[2] = *(volatile u32 *)VIF0_C2;
    regs->col[3] = *(volatile u32 *)VIF0_C3;
    regs->mask = *(volatile u32 *)VIF0_MASK;
    regs->code = *(volatile u32 *)VIF0_CODE;
    regs->stat = *(volatile u32 *)VIF0_STAT;
    regs->itop = *(volatile u32 *)VIF0_ITOP;
    regs->itops = *(volatile u32 *)VIF0_ITOPS;
    regs->mark = *(volatile u32 *)VIF0_MARK;
    regs->num = *(volatile u32 *)VIF0_NUM;
    regs->err = *(volatile u32 *)VIF0_ERR;
    regs->cycle_cl = cycle;
    regs->cycle_wl = cycle >> 8;
    regs->mode = *(volatile u32 *)VIF0_MODE;
    return 1;
}
