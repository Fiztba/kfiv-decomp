typedef struct
{
  int pad0[32];
  int p80;
  int p84;
  int p88;
  int p8c;
  int p90;
  int p94;
  int p98;
  int p9c;
  int pa0;
  int pa4;
  int pa8;
  int pac;
  int pb0;
  int pb4;
  int pb8;
} McState;
extern McState D_01E4F278;

int func_0021AE38(unsigned int arg0, unsigned int arg1, int arg2, int arg3, int arg4)
{
  McState *s = &D_01E4F278;

  if (s->p88 != 0)
    return 1;
  if (arg0 >= 3U || arg1 >= 5U)
    return -1;
  s->p98 = 0x3C;
  s->p88 = 7;
  s->p80 = arg0;
  s->p84 = arg1;
  s->pa0 = arg2;
  s->pb8 = arg3;
  s->pa8 = arg4;
  s->p8c = 0;
  s->p90 = 0;
  return 0;
}
