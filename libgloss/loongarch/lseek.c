/* SPDX-License-Identifier: GPL-2.0-only
 *
 * Copyright (C) 2023 Loongson Technology Corporation Limited
 */

#include "syscall.h"

int
_lseek (int file, int ptr, int dir)
{
  return syscall3 (SYS_lseek, file, ptr, dir);
}
