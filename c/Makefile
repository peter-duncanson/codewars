SRC = src/sum_by_factors.c
BUILD_DIR = build
TARGET = $(BUILD_DIR)/$(notdir $(SRC:.c=))
CC = gcc
CFLAGS = -Wall -Wextra -g

all: $(TARGET)

$(TARGET): $(SRC) | $(BUILD_DIR)
	$(CC) $(CFLAGS) -o $@ $<

$(BUILD_DIR):
	mkdir -p $(BUILD_DIR)

run: $(TARGET)
	./$(TARGET)

clean:
	rm -rf $(BUILD_DIR)

.PHONY: all run clean
