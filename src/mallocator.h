/**
 * @file mallocator.h
 * @author Joseph Leskey
 */

#ifndef MALLOCATOR_H
#define MALLOCATOR_H

#define MAX_REQUESTS 1000

/** Representation of a command-driven request and its associated data */
typedef struct Request
{
    /** Request allocation number */
    int id;
    /** Starting address of memory block */
    void *addr;
    /** Bytes allocated */
    unsigned int size;
    /** Stores an actual request */
    int valid;
} Request;

/** A request registry */
typedef struct RequestRegistry
{
    /** List of requests */
    Request requests[MAX_REQUESTS];
    /** Counter for used blocks*/
    int length;
    /** Counter for active blocks*/
    int count;
} RequestRegistry;

#endif // MALLOCATOR_H
