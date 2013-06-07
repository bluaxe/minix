#include <machine/asm.h>

IMPORT(_chrt)
ENTRY(_chrt)
	jmp	_C_LABEL(_chrt)

