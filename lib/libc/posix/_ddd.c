_#include <lib.h>
#define ddd _ddd
#include <unistd.h>

PUBLIC pid_t ddd()
{
  message m;

  return(_syscall(PM_PROC_NR, MINIX_GETPID, &m));
}
