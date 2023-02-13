/* SPDX-License-Identifier: GPL-2.0-only
 *
 * Copyright (C) 2023 Loongson Technology Corporation Limited
 */

  .text
  .globl  _start
  .type   _start, @function
_start:
  # Clear the bss segment
  la      $a0, __bss_start
  la      $a1, _end
1:
  st.b    $zero, $a0, 0
#if __loongarch_grlen == 32
  addi.w  $a0, $a0, 1
#else /* loongarch_grlen == 64 */
  addi.d  $a0, $a0, 1
#endif
  bne     $a0, $a1, 1b

  la      $a0, __libc_fini_array # Register global termination functions
  bl      atexit                 #  to be called upon exit
  bl      __libc_init_array      # Run global initialization functions

#if __loongarch_grlen == 32
  ld.w    $a0, $sp, 0            # a0 = argc
  addi.w  $a1, $sp, 4            # a1 = argv
#else /* loongarch_grlen == 64 */
  ld.d    $a0, $sp, 0            # a0 = argc
  addi.d  $a1, $sp, 8            # a1 = argv
#endif
  move    $a2, $zero             # a2 = envp = NULL
  bl      main
  b       exit
  .size   _start, .-_start
