#include "common.h"

void *func_001267B0(int);

/* Counts the first six objects whose flags low nibble is 3, then stores (count + 2) / 3. */
void func_00162B48(char *arg0) {
    char *sub;
    char *object;
    int count;
    int next;
    int i;

    sub = arg0 + 0xE0;
    count = 0;
    i = 0;
    do {
        object = func_001267B0(i + 0x65);
        if (object != NULL) {
            next = count + 1;
            count = (((*(long *)(object + 0xD8)) & 0xF) ^ 3) ? count : next;
        }
        i += 1;
    } while (i < 6);
    sub[0x7C] = (char)((count + 2) / 3);
}
