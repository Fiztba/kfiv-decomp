#include "common.h"

int func_00211A58(void *, int, int);
int func_00211AD0(void *, int, int);
int func_00211B48(void *, int, int);
extern char D_00432923[];

typedef struct {
    int unk0;
    int value;
} Operand;

/* Dispatch on the low byte of command[0] (0x11-0x13) with the int as the operand value. */
int func_00211CF8(int *command, int value) {
    Operand operand;
    int opcode;
    int high;
    int param;

    opcode = command[0];
    param = command[1];
    operand.value = value;
    high = opcode >> 8;
    switch (opcode & 0xFF) {
    case 0x11:
        return func_00211A58(&operand, high, param);
    case 0x12:
        return func_00211B48(&operand, high, param);
    case 0x13:
        return func_00211AD0(&operand, high, param);
    default:
        D_00432923[0] = 1;
    }
}
