/**
 * @file helperFunct.c - Helper Functions
 *
 * @author Cory Lamming (TheMasterCoder007)
 * @version 1.0
 * @date 2024-11-29
 *
 * @details
 * This file contains helper functions that are shared from puzzle to puzzle
 */

/***********************************************************************************************************************
 * INCLUDES
 **********************************************************************************************************************/

#include <stdio.h>
#include <stdlib.h>
#include "helperFunct.h"

/***********************************************************************************************************************
 * PUBLIC HELPER FUNCTIONS
 **********************************************************************************************************************/

/**
 * @fn ReadInput
 *
 * @details
 * Reads the contents of a file into a dynamically allocated buffer.
 *
 * @param filename - The path to the file to be read
 *
 * @return Returns a PuzzleInput on success, or a PuzzleInput with NULL and 0 on failure.
 */
PuzzleInput ReadInput(const char* filename) {
    // open file
    FILE* input = fopen(filename, "r");
    if (!input) {
        printf("Unable to open file: %s\n", filename);
        return (PuzzleInput){NULL, 0};
    }

    // get file length
    fseek(input, 0, SEEK_END);
    const long size = ftell(input);
    fseek(input, 0, SEEK_SET);

    // allocate memory for reading in file contents
    char* buffer = malloc(size + 1);
    if (!buffer) {
        printf("Unable to allocate memory for file: %s\n", filename);
        fclose(input);
        return (PuzzleInput){NULL, 0};
    }

    // read file contents into the buffer
    fread(buffer, size, 1, input);
    buffer[size] = '\0';

    // close the file and return the buffer
    fclose(input);
    return (PuzzleInput){buffer, size};
}
