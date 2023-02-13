/* SPDX-License-Identifier: GPL-2.0-only
 *
 * Copyright (C) 2023 Loongson Technology Corporation Limited
 */

#include "stat.h"
#include "syscall.h"

int
_unlink (char *name)
{
  return syscall3 (SYS_unlinkat, AT_FDCWD, (long)name, 0);
}
