/* SPDX-License-Identifier: GPL-2.0-only
 *
 * Copyright (C) 2023 Loongson Technology Corporation Limited
 */

#include "stat.h"
#include "syscall.h"

int
_open (char *file, int flags, int mode)
{
  return syscall4 (SYS_openat, AT_FDCWD, (long)file, flags, mode);
}
