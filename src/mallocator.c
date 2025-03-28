/**
 * @file mallocator.c
 * @author Joseph Leskey
 */

#include "lib/cypress/cypress.h"
#include "mallocator.h"
#include "functions.h"
#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>

int main(int argc, char *argv[])
{
    RequestRegistry registry = createRegistry();

    printIntro(argc ? argv[0] : "./mallocator");

    while (1)
    {
        char *input = promptInput(">>>", J_TRIM_REDUCE, false);

        char command = input[0];

        if (command == 'a')
        {
            unsigned int size;

            if (sscanf(&input[2], "%u", &size) == 1)
            {
                if (input[2] != '-')
                {
                    allocateBlock(&registry, size);
                }
                else
                {
                    printf("Please provide a positive block size.\n");
                }
            }
            else
            {
                printf("Please provide the allocation block size in bytes.\n");
            }
        }
        else if (command == 'd')
        {
            int id;

            if (sscanf(&input[2], "%d", &id) == 1)
            {
                deallocateBlock(&registry, id);
            }
            else
            {
                printf("Please provide the allocation block number.\n");
            }
        }
        else if (command == 'S')
        {
            listBlocks(&registry);
        }
        else if (command == 'X')
        {
            return EXIT_SUCCESS;
        }
        else
        {
            printf("Unknown command: %c\n", command);
        }
    }
}
