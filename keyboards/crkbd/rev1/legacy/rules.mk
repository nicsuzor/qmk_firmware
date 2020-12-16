CUSTOM_MATRIX = yes

SRC += 	matrix.c \
		split_util.c \
		split_scomm.c
LIB_SRC += ssd1306.c

QUANTUM_LIB_SRC += i2c.c serial.c
