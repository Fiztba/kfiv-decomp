void sceVu0RotMatrixX(float, int *, int *);
void sceVu0RotMatrixY(float, int *, int *);
void sceVu0ApplyMatrix(float *, int *, float *);
extern int D_00431AF0[];

void func_001AEC48(char *);
void func_001AED58(char *);
void func_001AF0B0(char *);
void func_001AF5B0(void *, void *);
void func_00216778(void *, void *);

void func_001A8678(char *arg0) {
    int m[16];
    float v[4];
    float w[4];
    char *s;

    s = arg0 + 0x10;
    func_001AEC48(arg0);
    func_001AED58(arg0);
    func_001AF0B0(arg0);
    v[0] = v[2] = v[3] = 0.0f;
    v[1] = 1.0f;
    func_001AF5B0(w, *(char **)(arg0 + 0x60) + 0x10);
    sceVu0RotMatrixX(w[0], m, D_00431AF0);
    sceVu0RotMatrixY(w[1], m, m);
    sceVu0ApplyMatrix(v, m, v);
    func_001AF5B0(*(char **)(arg0 + 0x50) + 0xD0, v);
    func_00216778(*(char **)(arg0 + 0x50) + 0xC0, s);
    func_00216778(s, *(char **)(*(char **)(arg0 + 0x60) + 0x50) + 0xC0);
    *(unsigned short *)(arg0 + 0x4C) += 1;
}
