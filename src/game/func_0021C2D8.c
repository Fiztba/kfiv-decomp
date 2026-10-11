#include "common.h"

typedef struct {
    int unk00;
    char pad04[0x40];
    int unk44;
    char pad48[0x10];
    int unk58;
} Buf;

int sceSifFreeIopHeap(int);
int printf(char *, ...);
int func_0021CC60(int);
extern char D_004420F8[];
extern char D_00442118[];

int func_0021C2D8(Buf *buf) {
    if (sceSifFreeIopHeap(buf->unk44) < 0) {
        printf(D_004420F8, D_00442118, 0x3AE);
    }
    if (sceSifFreeIopHeap(buf->unk58) < 0) {
        printf(D_004420F8, D_00442118, 0x3B0);
    }
    func_0021CC60(0);
    return 1;
}
