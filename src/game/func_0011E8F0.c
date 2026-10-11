#include "common.h"
#include "kf_gs.h"

#define GS_REG_ALPHA_2 0x43
#define GS_REG_ZBUF_2  0x4F
#define GS_REG_TEST_2  0x48

typedef struct {
    char pad00[0x15C];
    float unk15C;
} Target;

void func_00109A50(void);
void func_00109A80(int, s64);
void func_00109AD0(void);
void func_0010AEB8(void *arg0);

/* Sets the GS Z-buffer, alpha and test registers for arg0, then hands it on. */
void func_0011E8F0(Target *arg0) {
    func_00109A50();
    if (arg0->unk15C < 128.0f) {
        func_00109A80(GS_REG_ZBUF_1, 0x10A000118L);
        func_00109A80(GS_REG_ZBUF_2, 0x10A000118L);
    } else {
        func_00109A80(GS_REG_ZBUF_1, 0xA000118L);
        func_00109A80(GS_REG_ZBUF_2, 0xA000118L);
    }
    func_00109A80(GS_REG_ALPHA_1, 0x44);
    func_00109A80(GS_REG_ALPHA_2, 9);
    func_00109A80(GS_REG_TEST_1, 0x5000D);
    func_00109A80(GS_REG_TEST_2, 0x5000D);
    func_00109AD0();
    func_0010AEB8(arg0);
}
