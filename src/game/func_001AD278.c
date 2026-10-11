extern char D_00413F80[];

void func_001AF928(void *, int);
void func_001AF640(void *, int);
void func_001AF538(float, void *, void *);
int func_001AFD08(void *, void *, void *);

void func_001AD278(char *arg0, int arg1) {
    float temp_f0;
    char *temp_s1;
    char *temp_s3;

    temp_s3 = *(char **)(arg0 + 0x60);
    temp_s1 = arg0 + 0x10;
    func_001AF928(arg0, arg1);
    func_001AF640(arg0, arg1);
    *(int *)(arg0 + 0x6C) = func_001AFD08(arg0, D_00413F80, D_00413F80 + 0x10);
    temp_f0 = *(float *)(temp_s3 + 0x10);
    *(float *)(temp_s1 + 0x10) = temp_f0;
    func_001AF538(temp_f0, temp_s1, *(char **)(arg0 + 0x50) + 0xD0);
    *(int *)(temp_s1 + 0x14) = 0;
    *(float *)(temp_s1 + 0x18) = 1.0f;
    *(char *)(temp_s1 + 0x20) = 0;
}
