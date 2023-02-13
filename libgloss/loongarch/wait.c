/* SPDX-License-Identifier: GPL-2.0-only
 *
 * Copyright (C) 2023 Loongson Technology Corporation Limited
 */

#include "syscall.h"

int
_wait (int *status)
{
  return syscall4 (SYS_wait4, -1, (long)status, 0, 0);
}
