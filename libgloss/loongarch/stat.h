#ifndef STAT_H
#define STAT_H

#include <stdint.h>
#include <sys/stat.h>

#define AT_FDCWD          -100
#define AT_NO_AUTOMOUNT   0x800

#define STATX_BASIC_STATS 0x000007ffU

struct statx_timestamp {
  int64_t tv_sec;
  uint32_t tv_nsec;
  int32_t __reserved;
};

struct statx {
  uint32_t stx_mask;
  uint32_t stx_blksize;
  uint64_t stx_attributes;
  uint32_t stx_nlink;
  uint32_t stx_uid;
  uint32_t stx_gid;
  uint16_t stx_mode;
  uint16_t __spare0[1];
  uint64_t stx_ino;
  uint64_t stx_size;
  uint64_t stx_blocks;
  uint64_t stx_attributes_mask;
  struct statx_timestamp stx_atime;
  struct statx_timestamp stx_btime;
  struct statx_timestamp stx_ctime;
  struct statx_timestamp stx_mtime;
  uint32_t stx_rdev_major;
  uint32_t stx_rdev_minor;
  uint32_t stx_dev_major;
  uint32_t stx_dev_minor;
  uint64_t stx_mnt_id;
  uint32_t stx_dio_mem_align;
  uint32_t stx_dio_offset_align;
  uint64_t __spare3[12];
};

void _conv_stat (struct stat *to, struct statx *from);

#endif
