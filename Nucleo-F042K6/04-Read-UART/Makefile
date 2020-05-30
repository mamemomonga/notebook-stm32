TARGET = 03-Printf
CUBEMX = ../CubeMX/uart-int

include $(CUBEMX).mk
include ../build.mk

serial:
	screen /dev/ttyACM0 38400

.PHONY: serial flash
