#include "common.h"
#include "kf_file.h"

extern int func_001CBD20(void);

typedef struct {
    int *w00;
    char *w04;
} Ctx;

/* Open the file named in ctx, read it into the buffer at *ctx->w00, then close it. */
int func_0019F6B8(Ctx *arg0) {
    int file_handle;

    if (func_001CBD20() == 0) {
        return -1;
    }
    file_handle = func_00102238(arg0->w04, 0, 1);
    func_001025C0(file_handle, (void *)*arg0->w00, -1);
    func_001024B0(file_handle);
    return 1;
}
