typedef struct {
    char pad0[0xEC];
    unsigned short uEC;
    unsigned short uEE;
    char pad1[0x18];
    unsigned short u108;
} Ctl;

typedef struct {
    char pad0[0x14];
    int i14;
} Sub;

typedef struct {
    char pad0[0x10];
    Sub sub;
    char pad1[0x24];
    unsigned short count;
    unsigned short u4E;
    char *p50;
    Ctl *p54;
} Actor;

extern int D_004468E0;
void func_001AEC48(void *);
void func_001AED58(void *);
void func_001AF0B0(void *);
void func_001AF298(void *, void *);
int func_001A2A18(void *);
int func_001C0E40(float, void *);
void sceVu0AddVector(void *, void *, void *);

void func_001A98D0(Actor *arg0) {
    char *s;
    int n;
    unsigned short c;

    D_004468E0 = 0;
    func_001AEC48(arg0);
    s = (char *)arg0 + 0x10;
    func_001AED58(arg0);
    func_001AF0B0(arg0);
    n = *(int *)(s + 0x14);
    if (n <= 0) {
        if (arg0->count < arg0->p54->u108 || arg0->p54->u108 == 0) {
            sceVu0AddVector(arg0->p50 + 0xC0, arg0->p50 + 0xC0, s);
            if (func_001C0E40(arg0->p54->uEC * 2, arg0->p50 + 0xC0) == 0) {
                func_001A2A18(arg0);
                return;
            }
            *(float *)(arg0->p50 + 0xC4) = *(float *)0x70000004;
        }
        c = arg0->p54->uEE;
        *(int *)(s + 0x14) = c;
        n = c;
    }
    *(int *)(s + 0x14) = n - 1;
    if (arg0->count >= 0x15) {
        func_001AF298(arg0, s + 0x18);
    }
    arg0->count = arg0->count + 1;
}
