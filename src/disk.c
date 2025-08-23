#include "disk_usage/disk.h"
#include <stdio.h>
#include <stdlib.h>

struct statvfs get_disk_info(const char* path) {
  struct statvfs vfs;

  if (statvfs(path, &vfs) != 0) {
    perror("statvfs");
    exit(EXIT_FAILURE);
  }

  return vfs;
}

double bytes_to_mb(unsigned long bytes) {
  return bytes / 1024.0 / 1024.0;
}

double bytes_to_gb(unsigned long bytes) {
  return bytes / 1024.0 / 1024.0 / 1024.0;
}
