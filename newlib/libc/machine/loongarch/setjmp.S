#include <machine/asm.h>

#define GPR_NUM 13

#define GPR_LAYOUT		\
	GPR_OFFSET ($ra, 0);	\
	GPR_OFFSET ($sp, 1);	\
	GPR_OFFSET ($r21, 2);	\
	GPR_OFFSET ($fp, 3);	\
	GPR_OFFSET ($s0, 4);	\
	GPR_OFFSET ($s1, 5);	\
	GPR_OFFSET ($s2, 6);	\
	GPR_OFFSET ($s3, 7);	\
	GPR_OFFSET ($s4, 8);	\
	GPR_OFFSET ($s5, 9);	\
	GPR_OFFSET ($s6, 10);	\
	GPR_OFFSET ($s7, 11);	\
	GPR_OFFSET ($s8, 12);

#define FPR_LAYOUT		\
	FPR_OFFSET ($fs0, 0);	\
	FPR_OFFSET ($fs1, 1);	\
	FPR_OFFSET ($fs2, 2);	\
	FPR_OFFSET ($fs3, 3);	\
	FPR_OFFSET ($fs4, 4);	\
	FPR_OFFSET ($fs5, 5);	\
	FPR_OFFSET ($fs6, 6);	\
	FPR_OFFSET ($fs7, 7);

	.globl  setjmp
	.type   setjmp, @function
setjmp:
#define GPR_OFFSET(REG, OFFS) REG_S REG, $a0, OFFS * SZREG
#define FPR_OFFSET(REG, OFFS) FREG_S REG, $a0, GPR_NUM * SZREG + OFFS * SZFREG
	GPR_LAYOUT
	FPR_LAYOUT
#undef GPR_OFFSET
#undef FPR_OFFSET
	move	$a0, $zero
	jr	$ra
	.size	setjmp, .-setjmp

	.globl	longjmp
	.type	longjmp, @function
longjmp:
#define GPR_OFFSET(REG, OFFS) REG_L REG, $a0, OFFS * SZREG
#define FPR_OFFSET(REG, OFFS) FREG_L REG, $a0, GPR_NUM * SZREG + OFFS * SZFREG
	GPR_LAYOUT
	FPR_LAYOUT
#undef GPR_OFFSET
#undef FPR_OFFSET
	sltui	$a0, $a1, 1
	ADD	$a0, $a0, $a1	# a0 = (a1 == 0) ? 1 : a1
	jr	$ra
	.size	longjmp, .-longjmp
