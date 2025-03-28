/**
 * @file functions.c
 * @author Joseph Leskey
 */

#include "lib/cypress/cypress.h"
#include "mallocator.h"
#include "functions.h"
#include <stdio.h>
#include <stdlib.h>

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

RequestRegistry createRegistry()
{
    RequestRegistry registry;
    registry.length = 0;
    registry.count = 0;
    return registry;
}

void allocateBlock(RequestRegistry *registry, unsigned int size)
{
    if (registry->length < MAX_REQUESTS)
    {
        void *allocation = malloc(size);
        if (allocation)
        {
            registry->requests[registry->length].id = registry->length;
            registry->requests[registry->length].addr = allocation;
            registry->requests[registry->length].size = size;
            registry->requests[registry->length].valid = 1;
            printf("Allocated Block %d at %p (%u bytes)\n", registry->length,
                   allocation, size);
            registry->length++;
            registry->count++;
        }
        else
        {
            printf("Could not allocate memory.\n");
        }
    }
    else
    {
        printf("The request registry is full.\n");
    }
}

void deallocateBlock(RequestRegistry *registry, int id)
{
    if (id >= 0 && id < registry->length && registry->requests[id].valid)
    {
        free(registry->requests[id].addr);
        registry->requests[id].addr = NULL;
        registry->requests[id].valid = 0;
        printf("Deallocated block %d at %p (%u bytes)\n", id,
               registry->requests[id].addr, registry->requests[id].size);
        registry->count--;
    }
    else
    {
        printf("Could not locate block %d.\n", id);
    }
}

void listBlocks(RequestRegistry *registry)
{
    if (registry->count)
    {
        JTableProperties table = jTableInit(3, "ID", "Address", "Size");

        for (int i = 0; i < registry->length; i++)
        {
            Request req = registry->requests[i];

            if (req.valid)
            {
                int idLength = jlenf("%d", req.id);
                int addrLength = jlenf("%p", req.addr);
                int sizeLength = jlenf("%u bytes", req.size);

                jTableAdjust(&table, idLength, addrLength, sizeLength);
            }
        }

        jTableRow(&table, "ID", "Address", "Size");

        for (int i = 0; i < registry->length; i++)
        {
            Request req = registry->requests[i];

            if (req.valid)
            {
                char idString[J_INT_STRING_SIZE];
                char addrString[J_PTR_STRING_SIZE];
                char sizeString[J_UINT_STRING_SIZE];

                intToString(idString, J_INT_STRING_SIZE, req.id);
                ptrToString(addrString, J_PTR_STRING_SIZE, req.addr);
                uintToString(sizeString, J_UINT_STRING_SIZE, req.size);

                jTableRow(&table, idString, addrString, sizeString);
            }
        }

        jTableBorder(&table);
    }
    else
    {
        printf("The registry is empty.\n");
    }
}
