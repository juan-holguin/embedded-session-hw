# Makefile (root)
CC = gcc
CFLAGS = -Wall -Wextra -std=c11 -O2
SRCS = controller/ctl.c sensor/sensor.c actuators/led_actuator.c actuators/buzzer_actuator.c
OBJS = $(SRCS:.c=.o)

.PHONY: all ctl64 ctl32 clean

all: ctl64

ctl64:
	$(CC) $(CFLAGS) -o ctl64 $(SRCS)

# 32-bit binary (requiere toolchain/libs 32-bit)
ctl32:
	$(CC) $(CFLAGS) -m32 -o ctl32 $(SRCS) || (echo "Error building 32-bit. Instala librerías/headers 32-bit (e.g. libc6-dev-i386 en Linux)"; false)

clean:
	-rm -f ctl64 ctl32 *.o */*.o
