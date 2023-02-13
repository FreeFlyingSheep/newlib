/* SPDX-License-Identifier: GPL-2.0-only
 *
 * Copyright (C) 2023 Loongson Technology Corporation Limited
 */

#ifndef SYSCALL_H
#define SYSCALL_H

#define SYS_unlinkat     35
#define SYS_symlinkat    36
#define SYS_linkat       37
#define SYS_chdir        49
#define SYS_fchmodat     53
#define SYS_fchownat     54
#define SYS_openat       56
#define SYS_close        57
#define SYS_lseek        62
#define SYS_read         63
#define SYS_write        64
#define SYS_readlinkat   78
#define SYS_utimensat    88
#define SYS_exit         93
#define SYS_kill         129
#define SYS_gettimeofday 169
#define SYS_getpid       172
#define SYS_wait4        260
#define SYS_statx        291

extern int errno;

static inline long
__syscall_ret (long a0)
{
  if (a0 < 0) {
    errno = -a0;
    return -1;
  }
  return a0;
}

static inline long
syscall0 (long n)
{
  register long _a0 asm("a0");
  register long _a7 asm("a7") = n;
  asm volatile("syscall 0"
               : "=r" (_a0)
               : "r" (_a7)
               : "memory", "$t0", "$t1", "$t2", "$t3", "$t4", "$t5", "$t6", "$t7", "$t8");
  return __syscall_ret (_a0);
}

static inline long
syscall1 (long n, long a0)
{
  register long _a0 asm("a0") = a0;
  register long _a7 asm("a7") = n;
  asm volatile("syscall 0"
               : "+r" (_a0)
               : "r" (_a7)
               : "memory", "$t0", "$t1", "$t2", "$t3", "$t4", "$t5", "$t6", "$t7", "$t8");
  return __syscall_ret (_a0);
}

static inline long
syscall2 (long n, long a0, long a1)
{
  register long _a0 asm("a0") = a0;
  register long _a1 asm("a1") = a1;
  register long _a7 asm("a7") = n;
  asm volatile("syscall 0"
               : "+r" (_a0), "+r" (_a1)
               : "r" (_a7)
               : "memory", "$t0", "$t1", "$t2", "$t3", "$t4", "$t5", "$t6", "$t7", "$t8");
  return __syscall_ret (_a0);
}

static inline long
syscall3 (long n, long a0, long a1, long a2)
{
  register long _a0 asm("a0") = a0;
  register long _a1 asm("a1") = a1;
  register long _a2 asm("a2") = a2;
  register long _a7 asm("a7") = n;
  asm volatile("syscall 0"
               : "+r" (_a0), "+r" (_a1), "+r" (_a2)
               : "r" (_a7)
               : "memory", "$t0", "$t1", "$t2", "$t3", "$t4", "$t5", "$t6", "$t7", "$t8");
  return __syscall_ret (_a0);
}

static inline long
syscall4 (long n, long a0, long a1, long a2, long a3)
{
  register long _a0 asm("a0") = a0;
  register long _a1 asm("a1") = a1;
  register long _a2 asm("a2") = a2;
  register long _a3 asm("a3") = a3;
  register long _a7 asm("a7") = n;
  asm volatile("syscall 0"
               : "+r" (_a0), "+r" (_a1), "+r" (_a2), "+r" (_a3)
               : "r" (_a7)
               : "memory", "$t0", "$t1", "$t2", "$t3", "$t4", "$t5", "$t6", "$t7", "$t8");
  return __syscall_ret (_a0);
}

static inline long
syscall5 (long n, long a0, long a1, long a2, long a3, long a4)
{
  register long _a0 asm("a0") = a0;
  register long _a1 asm("a1") = a1;
  register long _a2 asm("a2") = a2;
  register long _a3 asm("a3") = a3;
  register long _a4 asm("a4") = a4;
  register long _a7 asm("a7") = n;
  asm volatile("syscall 0"
               : "+r" (_a0), "+r" (_a1), "+r" (_a2), "+r" (_a3), "+r" (_a4)
               : "r" (_a7)
               : "memory", "$t0", "$t1", "$t2", "$t3", "$t4", "$t5", "$t6", "$t7", "$t8");
  return __syscall_ret (_a0);
}

static inline long
syscall6 (long n, long a0, long a1, long a2, long a3, long a4, long a5)
{
  register long _a0 asm("a0") = a0;
  register long _a1 asm("a1") = a1;
  register long _a2 asm("a2") = a2;
  register long _a3 asm("a3") = a3;
  register long _a4 asm("a4") = a4;
  register long _a5 asm("a5") = a5;
  register long _a7 asm("a7") = n;
  asm volatile("syscall 0"
               : "+r" (_a0), "+r" (_a1), "+r" (_a2), "+r" (_a3), "+r" (_a4), "+r" (_a5)
               : "r" (_a7)
               : "memory", "$t0", "$t1", "$t2", "$t3", "$t4", "$t5", "$t6", "$t7", "$t8");
  return __syscall_ret (_a0);
}

#endif
