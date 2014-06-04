#include <lib.h>
#define ddd _ddd
#include <unistd.h>

PUBLIC void ddd()
{
  message m;

  return(_syscall(PM_PROC_NR,DDD, &m));
}
