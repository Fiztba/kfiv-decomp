void *func_001267B0(int);

void func_00216580(char *arg0) {
    char *temp_v0;

    temp_v0 = func_001267B0(*(int *)(arg0 + 0x8));
    if (temp_v0 != 0) {
        *(float *)(*(char **)temp_v0 + 0xC0) = *(float *)(arg0 + 0x10);
        *(float *)(*(char **)temp_v0 + 0xC4) = *(float *)(arg0 + 0x18);
        *(float *)(*(char **)temp_v0 + 0xC8) = *(float *)(arg0 + 0x20);
    }
    *(int *)arg0 = 0;
}
