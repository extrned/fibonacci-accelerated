TARGET = fibonacci-accelerated

CC = gcc
CFLAGS = -Wall -Wextra -O2 -I./fibonacci_accelerated/Headers

SRC_DIR = fibonacci_accelerated/Sources
OBJ_DIR = build

SRCS = $(SRC_DIR)/fibonacci.c
OBJS = $(SRCS:$(SRC_DIR)/%.c=$(OBJ_DIR)/%.o)

all: $(TARGET)
$(TARGET): $(OBJS)
	$(CC) $(CFLAGS) -o $@ $^
$(OBJ_DIR)/%.o: $(SRC_DIR)/%.c | $(OBJ_DIR)
	$(CC) $(CFLAGS) -c $< -o $@

$(OBJ_DIR):
	mkdir -p $(OBJ_DIR)

clean:
	rm -rf $(OBJ_DIR) $(TARGET)

.PHONY: all clean
