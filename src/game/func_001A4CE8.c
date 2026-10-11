typedef struct {
    char pad0[0x108];
    unsigned short u108;
    char pad1[0xE];
    unsigned short u118;
} Ctl;

typedef struct {
    char pad0[0x10];
    unsigned short u10;
} Sub;

typedef struct {
    char pad0[0x10];
    Sub sub;
    char pad1[0x48 - 0x22];
    void *p48;
    unsigned short count;
    unsigned short u4E;
    char *p50;
    Ctl *p54;
    char pad2[4];
    int i5C;
} Actor;

void func_001AEC48(void *);
void func_001AED58(void *);
void func_001AF0B0(void *);
int func_001B4F90(void *);
int func_001A2A18(void *);
void func_001A1E28(unsigned short, void *, void *, int, unsigned short, void *);
void sceVu0AddVector(void *, void *, void *);

void func_001A4CE8(Actor *arg0) {
    char *s;
    char *p50;

    func_001AEC48(arg0);
    s = (char *)arg0 + 0x10;
    func_001AED58(arg0);
    func_001AF0B0(arg0);
    if (arg0->count < arg0->p54->u108 || arg0->p54->u108 == 0) {
        sceVu0AddVector(arg0->p50 + 0xC0, arg0->p50 + 0xC0, s);
    }
    if (func_001B4F90(arg0) != 0 || *(unsigned short *)(s + 0x10) == arg0->count) {
        p50 = arg0->p50;
        func_001A1E28(arg0->p54->u118, p50 + 0xC0, p50 + 0xD0, arg0->i5C, arg0->u4E, arg0->p48);
        func_001A2A18(arg0);
    }
    arg0->count = arg0->count + 1;
}
