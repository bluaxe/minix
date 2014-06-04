#include <lib.h>
#define ddd _ddd
#include <unistd.h>

PUBLIC void ddd(arg)
_CONST int arg
{
  message m;
  m.m3_i1 = arg;

  return(_syscall(PM_PROC_NR,DDD, &m));
}
