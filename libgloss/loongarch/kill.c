/* SPDX-License-Identifier: GPL-2.0-only
 *
 * Copyright (C) 2023 Loongson Technology Corporation Limited
 */

#include "syscall.h"

int
_kill (int pid, int sig)
{
  return syscall2 (SYS_kill, pid, sig);
}
