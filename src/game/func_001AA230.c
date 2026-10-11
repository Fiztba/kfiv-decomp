void func_001AF928(char *, int);
void func_001AF640(void *, int);
void func_001A2838(unsigned short, void *);

void func_001AA230(char *arg0, int arg1) {
    char *temp_s0;
    char *temp_v0;

    temp_s0 = arg0 + 0x10;
    func_001AF928(arg0, arg1);
    func_001AF640(arg0, arg1);
    temp_v0 = *(char **)(arg0 + 0x54);
    *(unsigned short *)(arg0 + 0x10) = *(unsigned short *)(temp_v0 + 0xEC);
    *(unsigned short *)(temp_s0 + 2) = *(unsigned short *)(temp_v0 + 0xEE);
    if (*(unsigned short *)(temp_v0 + 0xF0) != 0) {
        func_001A2838(*(unsigned short *)(temp_v0 + 0xF0), arg0);
    }
    if (*(unsigned short *)(*(char **)(arg0 + 0x54) + 0xF2) != 0) {
        func_001A2838(*(unsigned short *)(*(char **)(arg0 + 0x54) + 0xF2), arg0);
    }
}
