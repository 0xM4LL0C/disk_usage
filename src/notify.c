#include "disk_usage/notify.h"
#include <libnotify/notification.h>

static NotifyNotification* n = NULL;

bool notify(const char* title, const char* message, const char* icon,
            const NotifyUrgency urgency) {
  if (!n) {
    n = notify_notification_new(title, message, icon);
  } else {
    notify_notification_update(n, title, message, icon);
  }

  notify_notification_set_urgency(n, urgency);

  if (!notify_notification_show(n, NULL)) {
    perror("Error showing notification");
    return false;
  }

  return true;
}
