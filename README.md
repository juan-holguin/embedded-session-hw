# embedded-session-hw

Proyecto de práctica: compilación, linking, headers, `extern`, y wrappers. Implementa:
- sensor modular,
- interfaz polimórfica para actuadores (LED, buzzer),
- controlador cerrado (muestreo cada 100 ms).

## Estructura
(explica la estructura de carpetas...)

## Build
Requisitos: `gcc`, `make`.
```bash
# build 64-bit
make ctl64

# build 32-bit (si tienes toolchain 32-bit)
make ctl32

# Proyecto: Embedded Systems Programming – Controlador de Temperatura

Este proyecto implementa un **controlador sencillo en C** que integra un **sensor** y dos **actuadores** (heater y cooler).  
Se desarrolla en **Ubuntu (WSL)** usando **VS Code** y se gestiona con **GitHub Desktop**.

---

## 📂 Estructura del proyecto
embedded-session-hw/
├── Makefile
├── README.md
├── ai_log.md
├── sensor/
│ ├── sensor.h
│ └── sensor.c
├── actuators/
│ ├── actuator.h
│ ├── led_actuator.c
│ └── buzzer_actuator.c
├── controller/
│ └── ctl.c
└── tests/
└── sensor_feed.csv

---

## ⚙️ Compilación

Se definieron dos binarios:

- **64 bits:**
  ```bash
  make ctl64

- **32 bits:**
  ```bash
  make ctl32

El controlador recibe como argumento un umbral de temperatura.
Ejemplo con 50 °C:

./ctl64 50

ejemplo de salida:

[0.000s] Sensor=47.2 °C | LED=OFF | Buzzer=OFF
[0.100s] Sensor=51.8 °C | LED=ON  | Buzzer=ON
[1.200s] Sensor=49.5 °C | LED=ON  | Buzzer=OFF
[5.300s] Sensor=48.7 °C | LED=OFF | Buzzer=OFF

Reflexiones sobre errores y diseño

Errores de compilación: ocurren si los headers no tienen guardas o si una función está mal declarada.

Errores de enlace (linking): aparecen cuando se declara una función en un .h pero no se implementa en un .c.

Uso de extern: permite declarar símbolos globales en headers y definirlos solo una vez en .c.

Wrappers polimórficos: permiten manejar actuadores diferentes (LED, buzzer) con la misma interfaz, lo que facilita la escalabilidad.

Lecciones aprendidas

La diferencia entre compilación y linking se entendió mejor separando el proyecto en módulos.

Usar un Makefile agiliza la compilación en 32 y 64 bits.

La modularidad (sensor, actuadores y controlador) hace más fácil extender el sistema.

VS Code + WSL + GitHub Desktop fue una combinación eficiente para programar en C y llevar control de versiones.