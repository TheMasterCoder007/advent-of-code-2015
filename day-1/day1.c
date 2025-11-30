/**
 * @file day1.c - Day 1: Not Quite Lisp
 *
 * @author Cory Lamming (TheMasterCoder007)
 * @version 1.0
 * @date 2024-11-30
 *
 * @details
 * This program helps Santa navigate a large apartment building
 */

/***********************************************************************************************************************
 * INCLUDES
 **********************************************************************************************************************/

#include <stdio.h>
#include <stdbool.h>

#include "helperFunct.h"

/***********************************************************************************************************************
 * PRIVATE FUNCTION PROTOTYPES
 **********************************************************************************************************************/

static long GetFloorNumberOfTarget(PuzzleInput instructions);

/***********************************************************************************************************************
 * PUBLIC FUNCTIONS
 **********************************************************************************************************************/

/**
 * @fn main
 *
 * @details
 * the programs main functions
 *
 * @return returns a integer, successful execution = 0, failure = 1
 */
int main() {
    // get instructions
    const PuzzleInput instructions = ReadInput("input.txt");
    if (!instructions.input) {
        printf("Failed to get input file contents.\n");
        return 1;
    }

    // find out what floor santa needs to be on
    printf("Santa needs to go to floor number %ld\n", GetFloorNumberOfTarget(instructions));
    return 0;
}

/***********************************************************************************************************************
 * PRIVATE FUNCTIONS
 **********************************************************************************************************************/

/**
 * @fn GetFloorNumberOfTarget
 *
 * @details
 * Parses the given instructions to determine the floor number Santa needs to be on.
 *
 * @param instructions - The puzzle input containing Santa's instructions
 *
 * @return The floor number Santa needs to be on as well as prints the first time Santa enters the basement
 */
static long GetFloorNumberOfTarget(PuzzleInput instructions) {
    // parse instructions to find out what floor Santa needs to be on
    bool foundFirstBasementEntry = false;
    long targetFloor = 0;
    for (long index = 0; index < instructions.inputLength; ++index) {
        if (instructions.input[index] == '(') {
            targetFloor++;
        } else if ( instructions.input[index] == ')' ) {
            targetFloor--;
        }

        // displays how many moves it takes for Santa to enter the basement for the first time
        if (targetFloor == -1 && !foundFirstBasementEntry) {
            foundFirstBasementEntry = true;
            printf("The first time that Santa enters the basement was on move %ld\n", index + 1);
        }
    }

    return targetFloor;
}