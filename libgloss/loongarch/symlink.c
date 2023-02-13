/* SPDX-License-Identifier: GPL-2.0-only
 *
 * Copyright (C) 2023 Loongson Technology Corporation Limited
 */

#include "stat.h"
#include "syscall.h"

int
_symlink (const char *path1, const char *path2)
{
  return syscall3 (SYS_symlinkat, (long)path1, AT_FDCWD, (long)path2);
}
