CC ?= clang
CFLAGS ?= -std=c11 -Wall -Wextra -Wpedantic
TARGET = flight-mode-controller

.PHONY: all run clean

all: $(TARGET)

$(TARGET): main.c
	$(CC) $(CFLAGS) main.c -o $(TARGET)

run: $(TARGET)
	./$(TARGET)

clean:
	rm -f $(TARGET)
