extern int D_003EF548[];
extern int D_00446858;
extern int D_004470F0;
extern int D_004470F4;

void func_00102218(void);
int func_00102230(void);
int func_00102238(char *, int, int);
int func_001025C0(int, int, int);
int func_00102900(int);
int func_001CBD20(void);
int sprintf(char *, char *, ...);

typedef struct {
    int *w00;
    int pad04;
    int pad08;
    char *w0C;
    int pad10[5];
    int w24;
} Ctx;

int func_0019EF68(Ctx *arg0, int arg1) {
    char sp[128];
    int temp_v0;
    int temp_v1;
    int *v;

    if (func_00102230() != 0) {
        return -1;
    }
    if (func_001CBD20() == 0) {
        return -1;
    }
    temp_v1 = D_004470F4;
    D_003EF548[0] = temp_v1;
    D_004470F4 = ((unsigned int)(temp_v1 + 0x2003F) >> 6) << 6;
    sprintf(sp, arg0->w0C, arg1);
    temp_v0 = func_00102238(sp, 1, 1);
    arg0->w24 = temp_v0;
    D_004470F0 = func_00102900(temp_v0);
    func_00102218();
    v = arg0->w00;
    func_001025C0(arg0->w24, v[2], -1);
    D_00446858 += 1;
    return 0;
}
