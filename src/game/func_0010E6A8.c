typedef struct E {
    char pad[0x78];
    unsigned long addr : 32;
    unsigned long pad2 : 21;
    unsigned long count : 11;
} E;

typedef struct O {
    char pad[0xF0];
    unsigned short n;
    char pad2[6];
    E *e;
} O;

void func_0010E6A8(O *arg0, long arg1, long arg2) {
    E *e;
    char *a;
    char *base;
    int i;
    int j;
    int c;
    int n;
    unsigned short cnt;
    int t;
    int b;
    int m;

    b = arg2;
    b &= 0x7FF;
    b <<= 15;
    m = arg1;
    m &= 0x7FF;
    m <<= 15;
    e = arg0->e;
    n = arg0->n;
    for (i = 0; i < n; i++, e++) {
        c = e->count;
        a = (char *)(int)e->addr;
        for (j = 0; j < c; j++) {
            base = a;
            cnt = *(unsigned short *)base;
            a += 0x70;
            t = *(int *)(a + 4) & 0x03FF8000;
            *(int *)(a + 4) = (t & ~m) | b | (*(int *)(a + 4) & 0xFC007FFF);
            a = base + (cnt + 1) * 0x10;
        }
    }
}
