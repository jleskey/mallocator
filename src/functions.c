/**
 * @file functions.c
 * @author Joseph Leskey
 * @date 18 March 2025
 */

 #include "mallocator.h"
 #include <stdio.h>

void printIntro(char *path)
{
    printf(
        "\n"
        "+---------------------------------+\n"
        "| Welcome to Joseph's Mallocator! |\n"
        "+---------------------------------+\n"
        "\n"
        "Usage: %s\n\n"
        "a <N>  –   Allocate N bytes of memory\n"
        "d <N>  –   Deallocate memory block at allocation number N\n"
        "S      –   List allocated memory blocks\n"
        "X      –   Exit\n"
        "\n",
        path);
}
