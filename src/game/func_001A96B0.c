typedef struct {
    char pad0[0x104];
    float f104;
} Ctl;

typedef struct {
    char pad0[4];
    float f4;
    char pad1[8];
    int i10;
    unsigned short u14;
} Sub;

typedef struct {
    char pad0[0x10];
    Sub sub;
    char pad1[0x48 - 0x28];
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
int func_001AF0B0(void *);
void func_001AF298(void *, void *);
void sceVu0AddVector(void *, void *, void *);
int func_001A2A18(void *);
void func_001A1E28(int, void *, void *, int, unsigned short, void *);

void func_001A96B0(Actor *arg0) {
    Sub *s;
    func_001AEC48(arg0);
    s = &arg0->sub;
    func_001AED58(arg0);
    func_001AF0B0(arg0);
    s->f4 = s->f4 + arg0->p54->f104;
    sceVu0AddVector(arg0->p50 + 0xC0, arg0->p50 + 0xC0, s);
    if (arg0->count > s->u14) {
        if (s->i10 == 5 || s->i10 == 3) {
            func_001A1E28(0x15, arg0->p50 + 0xC0, arg0->p50 + 0xD0, arg0->i5C, arg0->u4E, arg0->p48);
        }
        func_001A2A18(arg0);
        return;
    }
    func_001AF298(arg0, (char *)arg0 + 0x27);
    arg0->count++;
}
