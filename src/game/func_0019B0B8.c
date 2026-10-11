#include "common.h"

void func_00216778(void *, void *);

typedef struct Node
{
  char pad00[0xC];
  float unk0C;
  char pad10[0x10];
  void *unk20;
  char pad24[0x18];
  struct Node *next3C;
} Node;

extern Node *D_004470C8[2];

void func_0019B0B8(void)
{
  int i;
  Node *n;

  for (i = 0; i < 2; i++)
  {
    for (n = D_004470C8[i]; n != NULL; n = n->next3C)
    {
      if (n->unk20 != NULL)
      {
        float saved = n->unk0C;
        func_00216778(n, n->unk20);
        n->unk0C = saved;
      }
    }
  }
}
