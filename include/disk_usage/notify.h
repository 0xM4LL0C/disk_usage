#pragma once

#include <libnotify/notify.h>
#include <stdbool.h>

bool notify(const char* title, const char* message, const char* icon,
            const NotifyUrgency urgency);
