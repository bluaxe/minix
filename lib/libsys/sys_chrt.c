#include "syslib.h"

PUBLIC int sys_chrt(proc_ep, deadline)
endpoint_t proc_ep;		/* which proc_ep to be set*/
long deadline;			/* deadline  */
{
/* A process to be set real time.  Tell the kernel. */
  message m;

  m.CHRT_ENDPOINT = proc_ep;
  m.CHRT_DEAD_LINE= deadline;
  return(_kernel_call(SYS_CHRT, &m));
}

