/* SPDX-License-Identifier: GPL-2.0-only
 *
 * Copyright (C) 2023 Loongson Technology Corporation Limited
 */

#include "stat.h"

void
_conv_stat (struct stat *to, struct statx *from)
{
  to->st_dev     = ((from->stx_dev_minor & 0xff)
                   | (from->stx_dev_major << 8)
                   | ((from->stx_dev_minor & ~0xff) << 12));
  to->st_ino     = from->stx_ino;
  to->st_mode    = from->stx_mode;
  to->st_nlink   = from->stx_nlink;
  to->st_uid     = from->stx_uid;
  to->st_gid     = from->stx_gid;
  to->st_rdev    = ((from->stx_rdev_minor & 0xff)
                   | (from->stx_rdev_major << 8)
                   | ((from->stx_rdev_minor & ~0xff) << 12));
  to->st_size    = from->stx_size;
  to->st_blksize = from->stx_blksize;
  to->st_blocks  = from->stx_blocks;
  to->st_atime   = from->stx_atime.tv_sec;
  to->st_mtime   = from->stx_mtime.tv_sec;
  to->st_ctime   = from->stx_ctime.tv_sec;
}
