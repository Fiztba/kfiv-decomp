int sceSifFreeIopHeap(int);
int puts(char *);
void FlushCache(int);
extern char *D_004471D4;
extern char D_004469F0[];

typedef struct {
    int unk00;
    int unk04;
    int iop_heap;           /* 0x08 */
    int pad[5];
} Slot;

/* Release the IOP heap block of a slot; returns -1 if none was held or the free failed. */
int func_001CD7E0(int arg0) {
    Slot *slot;

    slot = (Slot *)(D_004471D4 + (arg0 << 5));
    if (slot->iop_heap == 0) {
        return -1;
    }
    if (sceSifFreeIopHeap(slot->iop_heap) != 0) {
        return -1;
    }
    puts(D_004469F0);
    slot->iop_heap = 0;
    FlushCache(0);
    return 0;
}
