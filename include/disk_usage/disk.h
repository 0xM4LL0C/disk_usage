#pragma once

#include <stddef.h>
#include <sys/statvfs.h>

struct statvfs get_disk_info(const char* path);
double bytes_to_mb(unsigned long bytes);
double bytes_to_gb(unsigned long bytes);
