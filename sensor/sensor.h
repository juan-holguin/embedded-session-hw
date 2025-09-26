#ifndef SENSOR_H
#define SENSOR_H

/* Sensor API: inicialización y lectura.
 * sensor_read devuelve un valor double (por ejemplo 0..100).
 */
void sensor_init(void);
double sensor_read(void);

#endif /* SENSOR_H */
