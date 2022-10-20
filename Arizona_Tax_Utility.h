#ifndef ARIZONA_TAX_UTILITY_H
#define ARIZONA_TAX_UTILITY_H
//Header Files
#include <stdbool.h>
#include <stdio.h>
#include <string.h>
#include "StandardConstants.h"



// global constants
    //AZ taxes
        // AZ tax Baseline RATE
static const double AZ_TAX_BASELINE_RATE = 0.0259;
        // AZ tax Baseline LIMIT
static const double AZ_TAX_BASELINE_LIMIT = 27808.5; 
        // AZ tax First bracket RATE
static const double AZ_TAX_FIRST_BRACKET_RATE = 0.0334;   
        // AZ tax First bracket LIMIT 
static const double AZ_TAX_FIRST_BRACKET_LIMIT = 55615.5;
        // AZ tax Second bracket RATE
static const double AZ_TAX_SECOND_BRACKET_RATE = 0.0417; 
        // AZ tax Second bracket LIMIT
static const double AZ_TAX_SECOND_BRACKET_LIMIT = 166843.5;
        // AZ tax MAX bracket RATE
static const double AZ_TAX_MAX_RATE = 0.045;

/*
Name: calculateArizonaTax
Process: calculates total marginal Arizona tax based on adjusted income
Function Input/Parameters: adjustedIncome
Function Output/Parameters: none
Function Output/Returned: total arizona tax
Device Input/Keyboard: none
Device Output/Monitor: none
Dependencies: none
*/

// function prototype
double calculateArizonaTax(double adjustedIncome);

#endif