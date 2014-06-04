#include <machine/asm.h>

IMPORT(_ddd)
ENTRY(yoursyscall)
	jmp	_C_LABEL(_ddd)

