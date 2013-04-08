#include <machine/asm.h>

IMPORT(_chrt)
ENTRY(chrt)
	jmp	_C_LABEL(_chrt)

