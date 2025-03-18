# Compiler settings
CC = gcc
CFLAGS = -Wall -Wextra

# Directories
SRC_DIR = src
OUT_DIR = out

# Files
SRCS = $(shell find $(SRC_DIR) -type f -name "*.c")
OBJS = $(patsubst $(SRC_DIR)/%.c, $(OUT_DIR)/%.o, $(SRCS))
TARGET = $(OUT_DIR)/mallocator

# Program binary
all: $(TARGET)

# Object linking
$(TARGET): $(OBJS)
	@mkdir -p $(OUT_DIR)
	$(CC) $(CFLAGS) -o $(TARGET) $(OBJS)

# Compilation
$(OUT_DIR)/%.o: $(SRC_DIR)/%.c
	@mkdir -p $(dir $@)
	$(CC) $(CFLAGS) -c $< -o $@

# Clean-up script
clean:
	rm -rf $(OUT_DIR)
