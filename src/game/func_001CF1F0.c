int func_001CBAE0();
extern char *D_004471D4;

typedef struct {
    unsigned int f0 : 5;
    unsigned int f5 : 1;
    unsigned int f6 : 7;
    unsigned int f13 : 3;
    unsigned int f16 : 4;
    unsigned int f20 : 4;
    unsigned int f24 : 7;
    unsigned int f31 : 1;
} Packed;

/* Sends slot arg0's two words with arg1; the reply is re-packed into *arg2 (some fields inverted). */
void func_001CF1F0(int arg0, int arg1, Packed *arg2) {
    char *slot;
    unsigned int v, w;

    slot = D_004471D4 + (arg0 << 5);
    v = func_001CBAE0(1, 0x110, *(int *)slot, *(int *)(slot + 0x10), arg1);
    w = ~v;
    arg2->f31 = v >> 31;
    arg2->f24 = w >> 24;
    arg2->f20 = w >> 20;
    arg2->f16 = v >> 16;
    arg2->f13 = v >> 13;
    arg2->f6 = w >> 6;
    arg2->f5 = v >> 5;
    arg2->f0 = w;
}
