SRC = src/sum_by_factors.c
TARGET = $(SRC:.c=)
CC = gcc
CFLAGS = -Wall -Wextra -g

all: $(TARGET)

$(TARGET): $(SRC)
	$(CC) $(CFLAGS) -o $@ $<

run: $(TARGET)
	./$(TARGET)

clean:
	rm -f $(TARGET)

.PHONY: all run clean

