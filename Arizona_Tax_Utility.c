// Header Files included
#include  "Arizona_Tax_Utility.h"


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

double calculateArizonaTax(double adjustedIncome) {

 // define variables
 double taxBracketRateAZ, azTAX;
 // Check Arizona Tax Bracket
       // functions: if, else if, else
           if (adjustedIncome < AZ_TAX_BASELINE_LIMIT)
           {
           taxBracketRateAZ = AZ_TAX_BASELINE_RATE;
           }

           else if ((adjustedIncome > AZ_TAX_BASELINE_LIMIT)
           && (adjustedIncome < AZ_TAX_FIRST_BRACKET_LIMIT))
           {
           taxBracketRateAZ = AZ_TAX_FIRST_BRACKET_RATE;
           }

           else if ((adjustedIncome > AZ_TAX_FIRST_BRACKET_LIMIT)
           && (adjustedIncome < AZ_TAX_SECOND_BRACKET_LIMIT))
           {
           taxBracketRateAZ = AZ_TAX_SECOND_BRACKET_RATE;
           }

           else if (adjustedIncome > AZ_TAX_SECOND_BRACKET_LIMIT)
           {
           taxBracketRateAZ = AZ_TAX_MAX_RATE;
           }


 // calculations
 // calculate AZ tax
 azTAX = adjustedIncome*taxBracketRateAZ;

 // end program
 return azTAX;

}