#include "common.h"

typedef struct {
    char unk0[0x4C4];
    int src;
    int unk4C8;
    int dest;
    char unk4D0[6];
    unsigned short active;
} DmaCtx;

int func_001CBAE0(int, int);
int sceSifDmaStat(int);
int sceSifSetDma(int *, int);
extern DmaCtx *D_004471D4;
extern int D_005BF8B8[];

/* Starts a DMA transfer with a 16-byte aligned size and waits for it, then clears the uncached word. */
int func_001CEBE0(void) {
    int *flag;
    int size;
    int id;
    int dest;

    if (D_004471D4->active == 0) {
        return -1;
    }
    flag = (int *)(D_004471D4->dest | 0x20000000);
    size = *flag + 4;
    while (size & 0xF) {
        size++;
    }
    dest = D_004471D4->dest;
    D_005BF8B8[1] = D_004471D4->src;
    D_005BF8B8[0] = dest;
    D_005BF8B8[2] = size;
    D_005BF8B8[3] = 0;
    id = sceSifSetDma(D_005BF8B8, 1);
    if (id == 0) {
        return -1;
    }
    while (sceSifDmaStat(id) >= 0) {
    }
    *flag = 0;
    func_001CBAE0(1, 0x1080);
    return 0;
}
