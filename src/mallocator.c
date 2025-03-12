#include "lib/jreadline/jreadline.h"
#include <stdio.h>
#include <stdlib.h>

void printIntro();

int main(int argc, char *argv[])
{
    printIntro(argc ? argv[0] : "./mallocator");

    while (1)
    {
        char *input = promptInput(">>>");

        char command = input[0];

        switch (command)
        {
        case 'X':
            exit(EXIT_SUCCESS);
            break;
        default:
            printf("Unknown command: %c\n", command);
            break;
        }
    }
}

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
