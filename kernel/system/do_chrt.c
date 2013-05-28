/* The kernel call that is implemented in this file:
  RTS_SET(rp, RTS_NO_QUANTUM);
 *   m_type:	SYS_CHRT
 *
 * The parameters for this kernel call are:
 *     m2_i1:	CHRT_ENDPOINT  # process to be set	
 *     m2_l1:	CHRT_DEAD_LINE # process deadline 
 */

#include "kernel/system.h"
#include <signal.h>

#if USE_CHRT


void kill_chrt(struct timer * tp){
	/* send termination signal to rt process */
	cause_sig(tp->tmr_arg.ta_int,SIGTERM);
	return ;
}

/*===========================================================================*
 *			          do_chrt*
 *===========================================================================*/
PUBLIC int do_chrt(struct proc * caller, message * m_ptr)
{

  proc_nr_t proc_nr, proc_nr_e;
  register struct proc *rp;

  long deadline = m_ptr->CHRT_DEAD_LINE;
  proc_nr_e= (proc_nr_t) m_ptr->CHRT_ENDPOINT;

  if (!isokendpt(proc_nr_e, &proc_nr)) return(EINVAL); 	/* find proc_nr */
  if (iskerneln(proc_nr)) return(EPERM);   				/* check if this slot if free */

  rp = proc_addr(proc_nr);
  RTS_SET(rp, RTS_NO_QUANTUM);

  if (deadline==0) {
  	rp->p_chrt_flag = 0;
  	if (rp->p_rt_timer.tmr_exp_time!=0) {
  		reset_timer(&rp->p_rt_timer);
  		rp->p_rt_timer.tmr_exp_time = 0;
  	}
  }
  else {
  	rp->p_chrt_flag = 1;	
  	if (rp->p_rt_timer.tmr_exp_time!=0) {
  		reset_timer(&rp->p_rt_timer);
  		rp->p_rt_timer.tmr_exp_time = 0;
  	}
  	rp->p_priority = 7 ;
  	rp->p_rt_timer.tmr_arg.ta_int = rp->p_nr;
  	rp->p_rt_timer.tmr_exp_time = deadline*60 + get_uptime();
  	rp->p_rt_timer.tmr_func = kill_chrt;
  	set_timer(&rp->p_rt_timer , rp->p_rt_timer.tmr_exp_time , kill_chrt );
  }

  RTS_UNSET(rp, RTS_NO_QUANTUM);

  return(OK);
}



#endif /* USE_CHRT*/

