#include "common.h"

void *memset(void *, int, unsigned int);
int FlushCache(int);
int sceClose(int);
int sceOpen(const char *, int);
int sceWrite(int, const void *, int);
void sceGsSyncPath(int, int);
void sceGsSetDefStoreImage(void *, short, short, short, short, short, short, short);
void sceGsExecStoreImage(void *, void *);
extern char D_0043EBB0[];

/* Dumps VRAM to a file, 32 blocks at a time, from base pointer arg0 through arg1. */
void func_0019BBA0(int arg0, int arg1) {
    char store_image[0x70];
    char buf[0x10000];
    int fd;
    int row;

    fd = sceOpen(D_0043EBB0, 0x202);
    if (fd >= 0) {
        for (row = arg0; row <= arg1; row += 0x20) {
            memset(buf, 0, 0x10000);
            sceGsSetDefStoreImage(store_image, row, 1, 0, 0, 0, 0x40, 0x20);
            FlushCache(0);
            sceGsExecStoreImage(store_image, buf);
            sceGsSyncPath(0, 0);
            sceWrite(fd, buf, 0x2000);
        }
        sceClose(fd);
    }
}
