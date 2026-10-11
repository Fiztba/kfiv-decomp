extern float D_00413F84[];

int atan2(int, int);
float dptofp(int);
int fptodp(float);
float func_00194FB8(float);
float func_00195388(float *, float, float);

void func_001491C0(char *arg0) {
    char *ctrl;
    char *s1;
    char *sub;
    int t1;
    float a;

    ctrl = *(char **)(arg0 + 0xC);
    s1 = *(char **)(*(char **)arg0 + 0xF8) + (*(short *)(ctrl + 0x434) << 7);
    sub = arg0 + 0xE0;
    if (s1 != 0) {
        t1 = fptodp(D_00413F84[0] - *(float *)(*(char **)arg0 + 0xC4));
        a = func_00194FB8(dptofp(atan2(t1, fptodp(*(float *)(arg0 + 0x64)))));
        if (0.87266463f < a) {
            a = 0.87266463f;
        } else if (a < -0.87266463f) {
            a = -0.87266463f;
        }
        func_00195388((float *)(sub + 0x58), a, 5.0f);
        *(float *)(s1 + 0x50) = *(float *)(sub + 0x58);
    }
}
