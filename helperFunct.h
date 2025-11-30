/**
 * @file helperFunct.h - Helper Functions
 *
 * @author Cory Lamming (TheMasterCoder007)
 * @version 1.0
 * @date 2024-11-29
 *
 * @details
 * This header file contains all function prototypes, public variables, types, and constants
 * that are shared across multiple puzzles in the Advent of Code 2015 challenge.
 */

#ifndef ADVENT_OF_CODE_2015_HELPERFUNCT_H
#define ADVENT_OF_CODE_2015_HELPERFUNCT_H

/***********************************************************************************************************************
 * TYPE DEFINITIONS & ENUMS
 **********************************************************************************************************************/

/**
 * @struct PuzzleInput
 * @brief Structure to hold puzzle input data
 */
typedef struct {
    char* input;
    const long inputLength;
} PuzzleInput;

/***********************************************************************************************************************
 * FUNCTION PROTOTYPES
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
PuzzleInput ReadInput(const char* filename);

#endif //ADVENT_OF_CODE_2015_HELPERFUNCT_H