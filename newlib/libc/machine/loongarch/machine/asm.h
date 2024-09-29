#ifndef _SYS_ASM_H
#define _SYS_ASM_H

#if __loongarch_grlen == 32
# define SZREG 4
# define REG_S st.w
# define REG_L ld.w
# define ADDI  addi.w
# define ADD   add.w
# define SUB   sub.w
#elif __loongarch_grlen == 64
# define SZREG 8
# define REG_S st.d
# define REG_L ld.d
# define ADDI  addi.d
# define ADD   add.d
# define SUB   sub.d
#else
# error "__loongarch_grlen must equal 32 or 64"
#endif

#ifndef __loongarch_soft_float
# if defined(__loongarch_single_float)
#  define SZFREG 4
#  define FREG_S fst.s
#  define FREG_L fld.s
# elif defined(__loongarch_double_float)
#  define SZFREG 4
#  define FREG_S fst.d
#  define FREG_L fld.d
# else
#  error "Unsupported floating point type"
# endif
#endif

#endif /* sys/asm.h */
