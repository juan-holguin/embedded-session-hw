#ifndef ACTUATOR_H
#define ACTUATOR_H

#include <stdbool.h>

/* Interfaz genérica para actuadores */
typedef struct actuator_s {
    void *params;
    void (*activate)(void *params);
    void (*deactivate)(void *params);
    bool (*status)(void *params); /* devuelve true si está activo */
} actuator_t;

/* Factory + destructor para los dos backends que vamos a usar */
actuator_t *led_actuator_create(const char *name, int pin);
void led_actuator_destroy(actuator_t *a);

actuator_t *buzzer_actuator_create(const char *name, int pin);
void buzzer_actuator_destroy(actuator_t *a);

#endif /* ACTUATOR_H */
