#define chrt _chrt
#include <lib.h>
#include <unistd.h>

PUBLIC void chrt(deadline)
long deadline;
{
  message m;

  m.m4_l1 = deadline;
  return (_syscall(PM_PROC_NR, CHRT, &m));
}

