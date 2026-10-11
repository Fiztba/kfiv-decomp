void func_001AF928(char *, int);
void func_001AF640(void *, int);
void func_001AF538(float, void *, void *);
short func_001B0208(float, void *, void *, void *);

void func_001AA330(char *arg0, int arg1) {
    char *temp_s1;
    char *temp_a0;
    short temp_v0;

    temp_s1 = arg0 + 0x10;
    func_001AF928(arg0, arg1);
    func_001AF640(arg0, arg1);
    func_001AF538(*(float *)(*(char **)(arg0 + 0x54) + 0xD8), temp_s1, *(char **)(arg0 + 0x50) + 0xD0);
    temp_v0 = func_001B0208((float)*(unsigned short *)(*(char **)(arg0 + 0x54) + 0xEC), arg0, temp_s1, arg0 + 0x20);
    *(char *)(temp_s1 + 0x24) = 0;
    *(short *)(temp_s1 + 0x22) = temp_v0;
    temp_a0 = *(char **)(arg0 + 0x54);
    *(unsigned short *)(temp_s1 + 0x20) = *(unsigned short *)(temp_a0 + 0x118);
    if (*(unsigned short *)(temp_a0 + 0xF2) != 0) {
        *(long *)(arg0 + 0x40) |= (long)0x8000 << 43;
    }
}
