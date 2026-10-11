#include "common.h"

extern int D_00446858;
extern int D_0044685C;
extern int D_00446F74;
extern int D_004470E8;
extern int D_004470F4;

void func_00102218(void);
int func_00102230(void);
int func_00102238(char *, int, int);
int func_001025C0(int, int, int);
int func_00102900(int);
int func_001CBD20(void);
int sprintf(char *, char *, ...);

typedef struct {
    int *resource;              /* 0x00 */
    char *name_format;          /* 0x04 */
    int pad08[7];
    int file_handle;            /* 0x24 */
} Ctx;

/* Pick a 64-byte aligned load address, open the file named by name_format and start reading it; -1 if busy. */
int func_0019EBB8(Ctx *ctx, int index) {
    char name[128];
    int handle;
    int load_addr;

    if (func_00102230() != 0) {
        D_0044685C = 1;
        return -1;
    }
    if (func_001CBD20() == 0) {
        return -1;
    }
    load_addr = ((u32)(D_00446F74 + 0x3F) >> 6) << 6;
    ctx->resource[0] = D_004470F4 = load_addr;
    D_004470F4 = load_addr + 0x80000;
    sprintf(name, ctx->name_format, index);
    handle = func_00102238(name, TRUE, TRUE);
    ctx->file_handle = handle;
    D_004470E8 = func_00102900(handle);
    func_00102218();
    func_001025C0(ctx->file_handle, ctx->resource[0], -1);
    D_00446858 += 1;
    return 0;
}
