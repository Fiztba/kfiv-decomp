#include "common.h"

void FlushCache(int);
void func_002007C0(char *);

typedef struct {
    char pad00[8];
    int a08;
    char *p0C;
    char pad10[0xC];
    int a1C;
    int a20;
} Obj;

/* Walk every chunk of the loaded package, hand each payload to func_002007C0, then flush. */
void func_001D44A0(Obj *arg0) {
    u32 i;
    u32 *header;
    char *next;
    char *chunk;

    header = *(u32 **)(arg0->p0C + 4);
    chunk = (char *)header + 0x10;
    for (i = 0; i < *header; i++) {
        next = chunk + *(int *)(chunk + 0xC);
        func_002007C0(chunk + *(int *)(chunk + 4));
        chunk = next + *(int *)(chunk + 8);
    }
    FlushCache(0);
    arg0->a20 = 1;
    arg0->a1C = 0;
    arg0->a08 = -1;
}
