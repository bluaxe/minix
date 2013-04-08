#include <machine/asm.h>

IMPORT(_getpid)
ENTRY(chrt)
	jmp	_C_LABEL(_chrt)

