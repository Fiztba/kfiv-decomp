#include "common.h"
#include "kf_file.h"

extern void func_00102228(void);
extern int func_001CE510(unsigned int);
extern void func_001CE408(int);
extern void func_001CD6E0(int);
extern int D_00446858;
extern int D_0044685C;

typedef struct {
    char pad[0x10];
    int f10;
    int f14;
    char pad18[0x24 - 0x18];
    int fd;
} Job;

/* Once the read on fd finishes, close it and release the job buffers. */
int func_0019EDA8(Job *arg0) {
    if (func_00102790(arg0->fd, 1) != 0) {
        return -1;
    }
    func_001024B0(arg0->fd);
    func_00102228();
    arg0->fd = -1;
    func_001CE510(arg0->f14);
    func_001CE408(arg0->f14);
    func_001CD6E0(arg0->f10);
    D_0044685C = 1;
    D_00446858 += 1;
    return 0;
}
