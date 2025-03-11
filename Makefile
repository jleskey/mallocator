# Compiler constants
CC = gcc
CFLAGS = -Wall -Wextra

# Program binary
all:
	$(CC) $(CFLAGS) -o out/mallocator src/mallocator.c src/lib/jreadline.c

# Clean-up script
clean:
	rm -r out/*
