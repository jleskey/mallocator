/**
 * @file functions.c
 * @author Joseph Leskey
 */

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
            printf("Allocated #%d at %p (%u bytes)\n", registry->length,
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
        registry->requests[id].valid = 0;
        printf("Allocated #%d at %p (%u bytes)\n", registry->length,
               registry->requests[id].addr, registry->requests[id].size);
        registry->count--;
    }
    else
    {
        printf("Could not locate block #%d.\n", id);
    }
}

void listBlocks(RequestRegistry *registry)
{
    if (registry->count)
    {
        for (int i = 0; i < registry->length; i++)
        {
            if (registry->requests[i].valid)
            {
                printf("ID: %d, Address: %p, Size: %u bytes\n",
                       registry->requests[i].id, registry->requests[i].addr,
                       registry->requests[i].size);
            }
        }
    }
    else
    {
        printf("The registry is empty.\n");
    }
}
