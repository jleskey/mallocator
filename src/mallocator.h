/**
 * @file mallocator.h
 * @author Joseph Leskey
 * @date 18 March 2025
 */

#ifndef MALLOCATOR_H
#define MALLOCATOR_H

/** Representation of a command-driven request and its associated data */
struct request
{
    /** Request allocation number */
    int id;
    /** Starting address of memory block */
    void *addr;
    /** Bytes allocated */
    unsigned int size;
    /** Stores an actual request */
    int valid;
};

/**
 * Prints welcome message and usage guide.
 *
 * @param[in] path Path to the mallocator binary
 */
void printIntro(char *path);

#endif // MALLOCATOR_H
