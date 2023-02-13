/* SPDX-License-Identifier: GPL-2.0-only
 *
 * Copyright (C) 2023 Loongson Technology Corporation Limited
 */

#include "syscall.h"

int
_getpid (void)
{
  return syscall0 (SYS_getpid);
}
