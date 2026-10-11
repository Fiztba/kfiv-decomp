typedef struct {
    int a;
    int b;
} Arg8;

void func_002020A0(int, Arg8);

void func_00202F50(int arg0, Arg8 arg1) {
    int base;
    int *p;
    int var_s0;
    int temp_s1;

    base = arg0;
    temp_s1 = base + 0x690;
    var_s0 = base;
    do {
        func_002020A0(var_s0, arg1);
        var_s0 += 0x70;
    } while (var_s0 < temp_s1);
    p = &base;
    var_s0 = *p + 0x700;
    temp_s1 = *p + 0x930;
    do {
        func_002020A0(var_s0, arg1);
        var_s0 += 0x70;
    } while (var_s0 < temp_s1);
}
