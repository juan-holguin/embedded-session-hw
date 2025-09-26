#define _POSIX_C_SOURCE 200809L
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <time.h>
#include <unistd.h> /* nanosleep */
#include <signal.h>

#include "../sensor/sensor.h"
#include "../actuators/actuator.h"

/* default threshold */
static double DEFAULT_THRESHOLD = 60.0;

/* helper: monotonic time (seconds as double) */
static double monotonic_now_sec(void) {
    struct timespec ts;
    clock_gettime(CLOCK_MONOTONIC, &ts);
    return (double)ts.tv_sec + (double)ts.tv_nsec / 1e9;
}

static volatile sig_atomic_t keep_running = 1;
static void sigint_handler(int _) { (void)_; keep_running = 0; }

int main(int argc, char **argv) {
    double threshold = DEFAULT_THRESHOLD;
    if (argc >= 2) threshold = atof(argv[1]);

    printf("Controller starting. threshold=%.2f\n", threshold);
    signal(SIGINT, sigint_handler);

    /* init sensor */
    sensor_init();

    /* create actuators (polymorphism via actuator_t) */
    actuator_t *led = led_actuator_create("status-led", 1);
    actuator_t *buzzer = buzzer_actuator_create("alarm-bzr", 2);
    if (!led || !buzzer) {
        fprintf(stderr, "Error creating actuators\n");
        return 1;
    }

    double start = monotonic_now_sec();
    double buz_off_deadline = -1.0;
    double led_off_deadline = -1.0;

    const struct timespec sleep_period = {0, 100 * 1000000}; /* 100 ms */

    while (keep_running) {
        double now = monotonic_now_sec();
        double t = now - start;

        double value = sensor_read();

        if (value >= threshold) {
            /* activate immediately and cancel deactivation timers */
            if (!led->status(led->params)) led->activate(led->params);
            if (!buzzer->status(buzzer->params)) buzzer->activate(buzzer->params);
            buz_off_deadline = -1.0;
            led_off_deadline = -1.0;
        } else {
            /* schedule deactivation only if not already scheduled */
            if (buz_off_deadline < 0.0) buz_off_deadline = t + 1.0; /* 1s */
            if (led_off_deadline < 0.0) led_off_deadline = t + 5.0; /* 5s */
        }

        /* check timers and deactivate if deadline reached */
        if (buz_off_deadline >= 0.0 && t >= buz_off_deadline) {
            if (buzzer->status(buzzer->params)) buzzer->deactivate(buzzer->params);
            buz_off_deadline = -1.0;
        }
        if (led_off_deadline >= 0.0 && t >= led_off_deadline) {
            if (led->status(led->params)) led->deactivate(led->params);
            led_off_deadline = -1.0;
        }

        /* Log: timestamp (rel), sensor value, LED state, buzzer state */
        printf("[LOG] t=%.3f s  sensor=%.3f  LED=%d  BUZ=%d\n",
               t, value,
               led->status(led->params) ? 1 : 0,
               buzzer->status(buzzer->params) ? 1 : 0);

        /* sleep ~100 ms (monotonic not required for nanosleep) */
        nanosleep(&sleep_period, NULL);
    }

    /* cleanup */
    led_actuator_destroy(led);
    buzzer_actuator_destroy(buzzer);

    printf("Controller exiting.\n");
    return 0;
}
