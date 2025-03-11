# Compiler constants
CC = gcc
CFLAGS = -Wall -Wextra

# Output directory
OUT_DIR = out

# Source files
SRC_FILES = src/mallocator.c src/lib/jreadline/jreadline.c

# Program binary
all: $(OUT_DIR)/mallocator

$(OUT_DIR)/mallocator: $(SRC_FILES)
	@mkdir -p $(OUT_DIR)
	$(CC) $(CFLAGS) -o $@ $^

# Clean-up script
clean:
	rm -rf $(OUT_DIR)/*
