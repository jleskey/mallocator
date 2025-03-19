/**
 * @file functions.h
 * @author Joseph Leskey
 * @date 19 March 2025
 */

 #ifndef MALLOCATOR_FUNCTIONS_H
 #define MALLOCATOR_FUNCTIONS_H

 #include "mallocator.h"

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
 * Lists all blocks of memory stored in the registry.
 *
 * @param[out] registry The registry
 */
void listBlocks(RequestRegistry *registry);

#endif // MALLOCATOR_FUNCTIONS_H
