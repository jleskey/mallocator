/**
 * @file mallocator.c
 * @author Joseph Leskey
 * @date 18 March 2025
 */

#include "lib/jreadline/jreadline.h"
#include "mallocator.h"
#include "functions.h"
#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>

int main(int argc, char *argv[])
{
    struct request registry[1000];

    printIntro(argc ? argv[0] : "./mallocator");

    while (1)
    {
        char *input = promptInput(">>>", J_TRIM_REDUCE, false);

        char command = input[0];

        if (command == 'a')
        {
            // TODO: Allocate a block
        }
        else if (command == 'd')
        {
            // TODO: Deallocate a block
        }
        else if (command == 'S')
        {
            // TODO: List allocated blocks
        }
        else if (command == 'X')
        {
            exit(EXIT_SUCCESS);
        }
        else
        {
            printf("Unknown command: %c\n", command);
        }
    }
}
