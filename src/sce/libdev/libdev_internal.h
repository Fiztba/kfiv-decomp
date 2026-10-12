/*
 * sce/libdev/libdev_internal.h
 *
 * libdev's COP2 control-register transfers and the prototypes its members
 * call each other through.  The transfers are inline asm: the period compiler
 * has no operand for them.  Each prototype is the signature of the member
 * that defines the symbol, which includes this header.
 */
#ifndef SCE_LIBDEV_LIBDEV_INTERNAL_H
#define SCE_LIBDEV_LIBDEV_INTERNAL_H

#define LIBDEV_CFC2(dst, vi) __asm__ __volatile__("cfc2.ni %0, $" #vi : "=r"(dst))
#define LIBDEV_CTC2(src, vi) __asm__ __volatile__("ctc2.ni %0, $" #vi : : "r"(src))

/* VIF and VU0 register windows (EE user's manual addresses). */
#include <eeregs.h>
#define LIBDEV_REG32(a) (*(volatile unsigned int *)(a))

/* A 128-bit register or memory quadword. */
typedef unsigned int DevU128 __attribute__((mode(TI)));

/* One VU0 quadword seen whole, as words, as halfwords or as two doublewords. */
typedef union {
    DevU128 whole;
    unsigned int words[4];
    unsigned short halves[8];
    struct {
        unsigned long long unk00;
        unsigned long long unk08;
    } parts;
} DevVu0Quad;

/* VU0 register file as sqc2/ctc2 move it: control registers vi16-vi18 and vi20-vi22. */
typedef struct {
    DevU128 vector_regs[32];
    unsigned int ctrl_regs[6];
    unsigned short int_regs[16];
} DevVu0Ctx;

/* VU0 register file as read through VU0's memory window: seven control registers. */
typedef struct {
    DevU128 vector_regs[32];
    unsigned int ctrl_regs[7];
    unsigned short int_regs[16];
} DevVu0MemCtx;

/* VIF0 register snapshot (0x38 bytes). */
typedef struct {
    unsigned int row[4];
    unsigned int col[4];
    unsigned int mask;
    unsigned int code;
    unsigned int stat;
    unsigned short itop;
    unsigned short itops;
    unsigned short mark;
    unsigned short num;
    unsigned char err;
    unsigned char cycle_cl;
    unsigned char cycle_wl;
    unsigned char mode;
} DevVif0Regs;

/* VIF1 register snapshot (0x40 bytes). */
typedef struct {
    unsigned int row[4];
    unsigned int col[4];
    unsigned int mask;
    unsigned int code;
    unsigned int stat;
    unsigned short itop;
    unsigned short itops;
    unsigned short base;
    unsigned short ofst;
    unsigned short top;
    unsigned short tops;
    unsigned short mark;
    unsigned short num;
    unsigned char err;
    unsigned char cycle_cl;
    unsigned char cycle_wl;
    unsigned char mode;
} DevVif1Regs;

int sceDevVu0IsRunning(void);
void sceDevVu0Pause(void);
int sceDevVu0Reset(void);
int sceDevVu0Continue(void);
void sceDevVu0PutStop(int on);
void sceDevVu0PutDbf(int on);
int sceDevVu0GetStop(void);
int sceDevVu0GetDbf(void);
int sceDevVu0GetStat(void);
void sceDevVu0Start(unsigned int addr);
unsigned int sceDevVu0GetTpc(void);
int sceDevVu0ChkIdle(void);
void sceDevVu0PutMem(unsigned int addr, void *src);
void sceDevVu0GetMem(void *dst, unsigned int addr);
unsigned short sceDevVu0GetTop(void);
void sceDevVu0PutTop(unsigned short top);
int sceDevVu0GetCnd(void);
int sceDevVu0ChkCnd(void);
int sceDevVu0Resume(void);
int sceDevVu0GetVi(void *ctx);
int sceDevVu0GetVf(void *ctx);
int sceDevVu0GetCtx(void *ctx);
int sceDevVu0PutCtx(void *ctx);
void sceDevVu0SetTBit(void);
void sceDevVu0PutEBit(int on);
void sceDevVu0PutMBit(int on);
int sceDevVu0GetEBit(void);
int sceDevVu0GetMBit(void);

int sceDevVif0Reset(void);
int sceDevVif0Pause(int mode);
int sceDevVif0Continue(void);
void sceDevVif0PutErr(unsigned int me0, unsigned int me1, unsigned int mii);
unsigned int sceDevVif0GetErr(void);
int sceDevVif0GetStat(void);
int sceDevVif0GetRegs(void *ctx);
int sceDevVif0PutFifo(void *src, int qwc);
int sceDevVif1Reset(void);
int sceDevVif1Pause(int mode);
int sceDevVif1Continue(void);
void sceDevVif1PutErr(unsigned int me0, unsigned int me1, unsigned int mii);
unsigned int sceDevVif1GetErr(void);
int sceDevVif1GetStat(void);
int sceDevVif1GetRegs(void *ctx);
int sceDevVif1PutFifo(void *src, int qwc);
int sceDevVif1GetFifo(void *dst, int qwc);

#endif /* SCE_LIBDEV_LIBDEV_INTERNAL_H */
