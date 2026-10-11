#include "common.h"

int vsprintf(char *, const char *, char *);
u32 strlen(char *);
void *memcpy(void *, const void *, u32);
extern char D_01E0E9C0[];

void func_00217EE0(char *fmt, char *args) {
    char buf[0x400];
    char *base;
    char *dst;
    int len;
    int used;

    vsprintf(buf, fmt, args);
    len = strlen(buf);
    base = D_01E0E9C0;
    used = *(int *)(base + 0x4C);
    if (len + used >= 0x801) {
        len = 0x800 - used;
    }
    dst = base + 0x50;
    memcpy(dst + used, buf, len);
    *(int *)(base + 0x4C) = *(int *)(base + 0x4C) + len;
}
