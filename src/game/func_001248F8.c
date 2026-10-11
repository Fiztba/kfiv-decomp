#include "common.h"
#include "kf_gs.h"

void func_00109A50(void);
void func_00109A80(int, unsigned long);
void func_00109AD0(void);
void func_0010AEB8(int *arg0);

void func_001248F8(int *arg0) {
    func_00109A50();
    func_00109A80(GS_REG_ZBUF_1, 0x10A000118L);
    func_00109A80(GS_REG_TEST_1, 0x50000);
    func_00109A80(GS_REG_ALPHA_1, 0x48);
    func_00109AD0();
    func_0010AEB8(arg0);
}
