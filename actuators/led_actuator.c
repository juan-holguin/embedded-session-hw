#include "actuator.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

typedef struct {
    int pin;
    bool active;
    char *name;
} led_params_t;

static void led_activate(void *p) {
    led_params_t *pr = (led_params_t *)p;
    if (!pr->active) {
        pr->active = true;
        /* simulación: imprimimos al stdout */
        printf("[ACTuator-LED] %s ON (pin %d)\n", pr->name, pr->pin);
    }
}

static void led_deactivate(void *p) {
    led_params_t *pr = (led_params_t *)p;
    if (pr->active) {
        pr->active = false;
        printf("[ACTuator-LED] %s OFF (pin %d)\n", pr->name, pr->pin);
    }
}

static bool led_status(void *p) {
    led_params_t *pr = (led_params_t *)p;
    return pr->active;
}

actuator_t *led_actuator_create(const char *name, int pin) {
    actuator_t *a = malloc(sizeof(actuator_t));
    if (!a) return NULL;
    led_params_t *p = malloc(sizeof(led_params_t));
    if (!p) { free(a); return NULL; }
    p->pin = pin;
    p->active = false;
    p->name = strdup(name ? name : "led");
    a->params = p;
    a->activate = led_activate;
    a->deactivate = led_deactivate;
    a->status = led_status;
    return a;
}

void led_actuator_destroy(actuator_t *a) {
    if (!a) return;
    led_params_t *p = (led_params_t *)a->params;
    if (p) {
        free(p->name);
        free(p);
    }
    free(a);
}
