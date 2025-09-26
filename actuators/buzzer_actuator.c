#include "actuator.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

typedef struct {
    int pin;
    bool active;
    char *name;
} buzzer_params_t;

static void buzzer_activate(void *p) {
    buzzer_params_t *pr = (buzzer_params_t *)p;
    if (!pr->active) {
        pr->active = true;
        printf("[ACTuator-BUZZER] %s ON (pin %d)\n", pr->name, pr->pin);
    }
}

static void buzzer_deactivate(void *p) {
    buzzer_params_t *pr = (buzzer_params_t *)p;
    if (pr->active) {
        pr->active = false;
        printf("[ACTuator-BUZZER] %s OFF (pin %d)\n", pr->name, pr->pin);
    }
}

static bool buzzer_status(void *p) {
    buzzer_params_t *pr = (buzzer_params_t *)p;
    return pr->active;
}

actuator_t *buzzer_actuator_create(const char *name, int pin) {
    actuator_t *a = malloc(sizeof(actuator_t));
    if (!a) return NULL;
    buzzer_params_t *p = malloc(sizeof(buzzer_params_t));
    if (!p) { free(a); return NULL; }
    p->pin = pin;
    p->active = false;
    p->name = strdup(name ? name : "buzzer");
    a->params = p;
    a->activate = buzzer_activate;
    a->deactivate = buzzer_deactivate;
    a->status = buzzer_status;
    return a;
}

void buzzer_actuator_destroy(actuator_t *a) {
    if (!a) return;
    buzzer_params_t *p = (buzzer_params_t *)a->params;
    if (p) {
        free(p->name);
        free(p);
    }
    free(a);
}
