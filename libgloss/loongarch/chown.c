/* SPDX-License-Identifier: GPL-2.0-only
 *
 * Copyright (C) 2023 Loongson Technology Corporation Limited
 */

#include <unistd.h>
#include "stat.h"
#include "syscall.h"

int
_chown (const char *path,
        uid_t owner,
        gid_t group)
{
  return syscall5 (SYS_fchownat, AT_FDCWD, (long)path, (long)owner, (long)group, 0);
}
