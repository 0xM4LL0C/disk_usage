#include "disk_usage/disk.h"
#include "disk_usage/notify.h"

#include <libnotify/notify-enum-types.h>
#include <stddef.h>
#include <stdbool.h>

int main() {
  notify_init("disk usage");

  while (true) {
    struct statvfs info = get_disk_info("/");

    double available_space_mb = bytes_to_mb(info.f_bavail * info.f_frsize);
    double available_space_gb = bytes_to_gb(info.f_bavail * info.f_frsize);

    double total_space_mb = bytes_to_mb(info.f_blocks * info.f_frsize);
    double total_space_gb = bytes_to_gb(info.f_blocks * info.f_frsize);

    char* message = malloc(100);
    sprintf(message, "Available space: %.2f MB / %.2f MB (%.2f GB / %.2f GB)",
            available_space_mb,
            total_space_mb, available_space_gb, total_space_gb);


    if (available_space_mb < 4000) {
      fprintf(stderr, "%s\n", message);
      notify("Disk Space Low", message, "dialog-error",
             NOTIFY_TYPE_URGENCY);
    }

    free(message);

    sleep(3);
  }

  notify_uninit();
  return 0;
}
