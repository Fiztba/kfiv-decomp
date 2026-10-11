int func_001CBAE0();
extern char *D_004471D4;

/* Send slot arg0's two words with arg1, and arg2 with its bit fields re-packed (some inverted). */
void func_001CF2E8(int arg0, int arg1, unsigned int arg2) {
    char *temp_t0;
    unsigned int packed;

    temp_t0 = D_004471D4 + (arg0 << 5);
    packed = (arg2 >> 31) << 31;
    packed |= ((((arg2 >> 24) & 0x7F) ^ 0x7F) << 24);
    packed |= ((((arg2 >> 20) & 0xF) ^ 0xF) << 20);
    packed |= arg2 & 0xF0000;
    packed |= arg2 & 0xE000;
    packed |= ((((arg2 >> 6) & 0x7F) ^ 0x7F) << 6);
    packed |= arg2 & 0x20;
    packed |= (arg2 & 0x1F) ^ 0x1F;
    func_001CBAE0(1, 0x120, *(int *)temp_t0, *(int *)(temp_t0 + 0x10), arg1, packed);
}
