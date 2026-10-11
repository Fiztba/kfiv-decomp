typedef struct {
    unsigned long long a;
    unsigned long long b;
} Pair;

extern Pair D_0043E8B0;
extern int D_00413F80[];

float func_00194FB8(float);
int func_0018E3D0(void *, int, int, int, void *, int, float);

void func_0013D588(char *arg0) {
    char pad[0x10]; /* unused, but retail reserves the 0x10 bytes */
    Pair tmp;
    char *temp_v0;
    char *temp_s0;
    float f;

    tmp = D_0043E8B0;
    temp_v0 = *(char **)arg0;
    temp_s0 = *(char **)(temp_v0 + 0xF8) + 0x180;
    if (temp_s0 != 0 && *(char *)(arg0 + 0xD1) == 0x11) {
        func_0018E3D0(temp_v0, (int)temp_s0, (int)(arg0 + 0x110), 1, D_00413F80, 0, 10.0f);
        f = *(float *)(temp_s0 + 0x50) - 2.0943952f;
        *(float *)(temp_s0 + 0x50) = f;
        *(float *)(temp_s0 + 0x50) = func_00194FB8(f);
    }
}
