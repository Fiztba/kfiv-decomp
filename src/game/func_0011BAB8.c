extern char D_0038CD20[];
extern int D_00446770;
extern float D_00413F80[];

int func_0011BAB8(int *arg0, int *arg1) {
    int t;
    char *row;

    row = D_0038CD20 + D_00446770 * 0x60;
    t = ((unsigned char *)row)[1];
    if (t >= 0x11) {
        if (t < 0x14) {
            *arg0 = (D_00413F80[0] - 0.0f) * 22.857143f / 1000.0f + 360.0f;
            *arg1 = 206.0f - (D_00413F80[2] - 0.0f) * 22.4f / 1000.0f;
            return 1;
        }
        if (t < 0x1A) {
            if (t >= 0x18) {
                *arg0 = (D_00413F80[0] - 0.0f) * 22.857143f / 1000.0f + 205.0f;
                *arg1 = 368.0f - (D_00413F80[2] - 0.0f) * 22.4f / 1000.0f;
                return 1;
            }
        }
    }
    return 0;
}
