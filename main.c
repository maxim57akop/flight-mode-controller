#include <stdbool.h>
#include <stdio.h>

typedef enum {
    MODE_IDLE,
    MODE_TAKEOFF,
    MODE_FLYING,
    MODE_LANDING,
    MODE_ERROR
} FlightMode;

static const char *mode_name(FlightMode mode)
{
    switch (mode) {
    case MODE_IDLE:
        return "IDLE";
    case MODE_TAKEOFF:
        return "TAKEOFF";
    case MODE_FLYING:
        return "FLYING";
    case MODE_LANDING:
        return "LANDING";
    case MODE_ERROR:
        return "ERROR";
    default:
        return "UNKNOWN";
    }
}

static bool can_transition(FlightMode current, FlightMode next)
{
    if (next == MODE_ERROR) {
        return true;
    }

    switch (current) {
    case MODE_IDLE:
        return next == MODE_TAKEOFF;
    case MODE_TAKEOFF:
        return next == MODE_FLYING;
    case MODE_FLYING:
        return next == MODE_LANDING;
    case MODE_LANDING:
        return next == MODE_IDLE;
    case MODE_ERROR:
        return next == MODE_IDLE;
    default:
        return false;
    }
}

static void request_mode_change(FlightMode *current, FlightMode next)
{
    printf("Request: %s -> %s\n", mode_name(*current), mode_name(next));

    if (can_transition(*current, next)) {
        *current = next;
        printf("Result: accepted\n\n");
    } else {
        printf("Result: rejected\n\n");
    }
}

int main(void)
{
    FlightMode mode = MODE_IDLE;

    request_mode_change(&mode, MODE_TAKEOFF);
    request_mode_change(&mode, MODE_FLYING);
    request_mode_change(&mode, MODE_IDLE);
    request_mode_change(&mode, MODE_LANDING);
    request_mode_change(&mode, MODE_IDLE);

    return 0;
}
