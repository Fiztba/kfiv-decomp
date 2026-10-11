#include "common.h"

int func_00208168();
int func_00208170(int);

typedef struct
{
  int unk00;
  int pad04;
  int unk08;
  char pad0c[0x78];
  int unk84;
} Obj;

void func_002120E0(Obj *arg0)
{
  if (arg0->unk84 == 0)
  {
    if (func_00208170(arg0->unk08) != 0)
    {
      arg0->unk84 = 1;
    }
  }
  else if (func_00208168() == 0)
  {
    arg0->unk00 = 0;
  }
}
