#include <lib.h>
#define ddd _ddd
#include <unistd.h>

PUBLIC void ddd(int arg, int deadline)
{
  message m;
  m.m3_i1 = arg;
  m.m3_i2 = deadline;

  return(_syscall(PM_PROC_NR,DDD, &m));
}
