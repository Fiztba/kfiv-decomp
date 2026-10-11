#include "common.h"

typedef struct {
    int pad0[32];
    int unk80;
    int unk84;
    int state;              /* 0x88 nonzero while a request is active */
    int unk8C;
    int unk90;
    int unk94;
    int timeout;            /* 0x98 */
    int unk9C;
    int unkA0;
    int unkA4;
    int unkA8;
    int unkAC;
    int unkB0;
    int unkB4;
} McState;
extern McState D_01E4F278;

/* Start a request unless one is active; returns 1 if busy, -1 on a bad argument, 0 on success. */
int func_0021ADD0(u32 arg0, u32 arg1, int arg2, int arg3, int arg4)
{
  McState *mc = &D_01E4F278;

  if (mc->state != 0)
    return 1;
  if (arg0 >= 3U || arg1 >= 5U)
    return -1;
  mc->timeout = 0x46;
  mc->state = 6;
  mc->unk80 = arg0;
  mc->unk84 = arg1;
  mc->unkA0 = arg2;
  mc->unkB4 = arg3;
  mc->unkA8 = arg4;
  mc->unk90 = mc->unk8C = 0;
  return 0;
}
