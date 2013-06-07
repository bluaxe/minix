#include "pm.h"
#include "param.h"
#include "glo.h"
#include "mproc.h"


/*===========================================================================*
 *				do_chrt *
 *===========================================================================*/
PUBLIC int do_chrt()
{
	/*
	 *
	 */
	if (mp->mp_scheduler == KERNEL || rmp->mp_scheduler == NONE)
		return (-1);

	m.SCHEDULING_ENDPOINT	= mp->mp_endpoint;
	m.SCHEDULING_DEADLINE   = m_in.m4_l1;
	
	if ((rv = _taskcall(rmp->mp_scheduler, SCHEDULING_SET_NICE, &m))) {
		return rv;
	}

	return (OK);

}

