/**
 * @file functions.h
 * @author Joseph Leskey
 */

#ifndef MALLOCATOR_FUNCTIONS_H
#define MALLOCATOR_FUNCTIONS_H

#include "mallocator.h"
#include <stdbool.h>

/**
 * Prints welcome message and usage guide.
 *
 * @param[in] path Path to the mallocator binary
 */
void printIntro(char *path);

/**
 * Creates and initializes a request registry.
 *
 * @returns A new request registry
 */
RequestRegistry createRegistry();

/**
 * Allocates and registers a block of memory.
 *
 * @param[out] registry The registry
 * @param[in] size The amount of memory to allocate
 */
void allocateBlock(RequestRegistry *registry, unsigned int size);

/**
 * Deallocates a block of memory stored in the registry.
 *
 * @param[out] registry The registry
 * @param[in] id The request allocation number
 */
void deallocateBlock(RequestRegistry *registry, int id);

/**
 * Writes a character to a block a given number of times.
 *
 * @param[out] registry The registry
 * @param[in] id The request allocation number
 * @param[in] count The number of characters to write
 * @param[in] character The character to write
 */
void writeToBlock(RequestRegistry *registry, int id, unsigned int count,
                  char character);

/**
 * Lists all blocks of memory stored in the registry.
 *
 * @param[out] registry The registry
 */
void listBlocks(RequestRegistry *registry);

/**
 * Checks if the given block exists.
 *
 * @param[out] registry The registry
 * @param[in] id The request allocation number
 */
bool blockExists(RequestRegistry *registry, int id);

#endif // MALLOCATOR_FUNCTIONS_H
