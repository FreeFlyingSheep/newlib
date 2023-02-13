/* SPDX-License-Identifier: GPL-2.0-only
 *
 * Copyright (C) 2023 Loongson Technology Corporation Limited
 */

#include "stat.h"
#include "syscall.h"

int
_link (char *existing, char *new)
{
  return syscall5 (SYS_linkat, AT_FDCWD, (long)existing, AT_FDCWD, (long)new, 0);
}
