#include "common.h"
#include "kf_gs.h"

void func_00109A50(void);
void func_00109A80(int, unsigned long);
void func_00109AD0(void);
void func_0010AEB8(void *arg0);

typedef struct {
    char pad0[0x15C];
    float alpha_level;
} Fx;

/* Sets the GS Z-buffer/test/alpha registers (by alpha_level), then hands off. */
void func_001247F8(Fx *arg0) {
    func_00109A50();
    if (arg0->alpha_level >= 128.0f) {
        func_00109A80(GS_REG_ZBUF_1, 0xA000118L);
        func_00109A80(0x4F, 0xA000118L); /* ZBUF_2 */
        func_00109A80(GS_REG_TEST_1, 0x5000D);
        func_00109A80(0x48, 0x5000D); /* TEST_2 */
    } else {
        func_00109A80(GS_REG_ZBUF_1, 0x10A000118L);
        func_00109A80(0x4F, 0x10A000118L); /* ZBUF_2 */
        func_00109A80(GS_REG_TEST_1, 0x5000D);
        func_00109A80(0x48, 0x30001); /* TEST_2 */
    }
    func_00109A80(GS_REG_ALPHA_1, 0x44);
    func_00109A80(0x43, 9); /* ALPHA_2 */
    func_00109AD0();
    func_0010AEB8(arg0);
}
