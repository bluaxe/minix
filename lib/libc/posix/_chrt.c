#include <lib.h>
#define chrt _chrt
#include <unistd.h>

PUBLIC int chrt(deadline)
_CONST long deadline;
{
  message m;

  /*TODO  -> add deadline to m */
  m.m4_l1=deadline;

  return(_syscall(PM_PROC_NR, CHRT, &m));
}
