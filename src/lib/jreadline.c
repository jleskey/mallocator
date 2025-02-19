/**
 * @file jreadline.c
 * @author Joseph Leskey
 * @date 28 January 2024
 */

#include "jreadline.h"
#include <stdio.h>
#include <stdlib.h>

char *promptInput(char const *prompt)
{
    char *response = NULL;

    // We want to get useable input.
    while (!response)
    {
        printf("%s ", prompt);
        response = jReadLine(stdin);
    }

#if PROMPT_NEWLINE
    printf("\n");
#endif

    return response;
}

char *jReadLine(FILE *stream)
{
    char *buffer = NULL;

    char c, prevC = '\0';
    int length = 0;

    // Loop through all input characters until newline or EOF.
    while ((c = fgetc(stream)) != '\n' && c != EOF)
    {
        // Strip extraneous whitespace.
        // NOTE: This can leave a whitespace at the end of the line.
        if (c != ' ' || (prevC != ' ' && length != 0))
        {
            // If the buffer is full or empty, allocate more space in
            // increments of `STRING_INCREMENT`.
            if (length % STRING_INCREMENT == 0)
            {
                // We need to increment the buffer size and leave a
                // space for a null character to complete the string.
                int newLength = length + STRING_INCREMENT + 1;

                // It would be a shame to lose the original buffer
                // reference if `realloc` fails. Let's avoid that.
                char *tempBuffer = realloc(buffer, sizeof(char) * newLength);
                if (!tempBuffer)
                {
                    free(buffer);
                    fprintf(stderr, "Memory allocation error.\n");
                    return NULL;
                }
                buffer = tempBuffer;
            }
            buffer[length++] = c;
        }
        prevC = c;
    }

    if (buffer)
    {
        if (prevC == ' ')
        {
            // We don't want a single space. Count this as empty.
            if (length == 1)
            {
                free(buffer);
                return NULL;
            }

            // We'll remove a trailing space.
            buffer[length - 1] = '\0';
        }
        else
        {
            // If we don't have to worry about a final space, we'll just
            // tidily close off the character array and make it an
            // official string.
            buffer[length] = '\0';
        }
    }

    return buffer;
}
