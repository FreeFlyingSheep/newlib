#include <machine/asm.h>
#include "newlib.h"

	.text
	.global	_start
	.type	_start, @function
_start:
	# Clear the bss segment
	la	$a0, _edata
	la	$a2, _end
	SUB	$a2, $a2, $a0
	move	$a1, $zero
	bl	memset
#ifdef _LITE_EXIT
	# Make reference to atexit weak to avoid unconditionally pulling in
	# support code.  Refer to comments in __atexit.c for more details.
	.weak	atexit
	la	$a0, atexit
	beqz	$a0, .Lweak_atexit
	.weak	__libc_fini_array
#endif
	la	$a0, __libc_fini_array	# Register global termination functions
	bl	atexit			#  to be called upon exit
#ifdef _LITE_EXIT
.Lweak_atexit:
#endif
	bl	__libc_init_array	# Run global initialization functions

	REG_L	$a0, $sp, 0		# a0 = argc
	ADDI	$a1, $sp, SZREG		# a1 = argv
	move	$a2, $zero		# a2 = envp = NULL
	bl	main
	b	exit
	.size	_start, .-_start
