/* The kernel call that is implemented in this file:
 *   m_type:	SYS_CHRT
 *
 * The parameters for this kernel call are:
 *     m2_i1:	CHRT_ENDPOINT  # process to be set	
 *     m2_l1:	CHRT_DEAD_LINE # process deadline 
 */

#include "kernel/system.h"

#if USE_CHRT

/*===========================================================================*
 *			          do_chrt*
 *===========================================================================*/
PUBLIC int do_chrt(struct proc * caller, message * m_ptr)
{

  proc_nr_t proc_nr, proc_nr_e;
  long deadline = m_ptr->CHRT_DEAN_LINE;

  proc_nr_e= (proc_nr_t) m_ptr->CHRT_ENDPOINT;

  //if (!isokendpt(proc_nr_e, &proc_nr)) return(EINVAL);
  //if (iskerneln(proc_nr)) return(EPERM);


  return(OK);
}

#endif /* USE_CHRT*/

