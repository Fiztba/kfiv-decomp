extern char D_0038CD20[];
extern int D_00446770;
extern int D_0038D680[];

void func_001187F0(int arg0) {
    char *row;

    row = D_0038CD20 + D_00446770 * 0x60;
    if (D_0038D680[6] == 0 && ((unsigned char *)row)[1] != arg0) {
        D_0038D680[6] = 1;
        D_0038D680[10] = 0x1E;
        D_0038D680[7] = arg0;
        D_0038D680[9] = 0;
        D_0038D680[4] = 0;
    }
}
