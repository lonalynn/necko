// header files
#include "Console_IO_Utility.h"
#include "File_Input_Utility.h"
#include "File_Output_Utility.h"
#include "Arizona_Tax_Utility.h"
#include "StandardConstants.h"

// constants

// function prototypes
void createOutputString(char *outputString, int year, double income);
void outputResultsToFile(const char *filename, const char * outputString);

int main()
   {
        
     // TODO

     // Define Variables
     char fileName[ STD_STR_LEN ], *outputString; int years; double income, totalIncome,
     outputIncome; int line;

    // a pointer to the output file's name.
     char *outputFilePtr;

     line = 1;
     
     // Show Title
        // functions: printString, printCharacters, printEndline(s)
        printString("DUMMY TAX CALCULATOR V0.4");
        printEndline();
        printCharacters('=', 27);
        printEndlines(2);

     // Get input
         // Get File name
             // functions: promptForString, printEndline
             promptForString("Enter file name containing income information: ",
             fileName);
             printEndline();

     // read file
     // open file and check if it was successful
        // function: fopen, print, if
        openInputFile(fileName);

     //check how much income was made
        // function: for, if, readDoubleFromFile,
        years = readIntegerFromFile();
        while(!checkForEndOfInputFile()) {
            if (line % 2 == 0) {
             income = readDoubleFromFile();
             totalIncome = totalIncome + income;
            }
            else if (line % 1 == 0) {
             years = readIntegerFromFile();
            }
            outputIncome = calculateArizonaTax(totalIncome);

            // passing the pointer outputString, years, and the calculated income
            createOutputString(outputString, years, outputIncome);

            // creating output file name
            sprintf(outputFilePtr, "Tax_Report_%d.txt", years);

            // passing a pointer to the output file name, and a pointer to the outputString.
            outputResultsToFile(outputFilePtr, outputString);

            line = line + 1;
        }

        printString("Arizona Tax for 8 years has been calculated.");
        printEndline();
        printString("The results can be viewed in the report files.");

        // End program
        printString("\nEnd Program");
        return 0;
    }



void createOutputString(char *outputString, int year, double income)
{
// this helper function prints (copies) an output string to outputString.
 sprintf(outputString, "For the tax year %d total AZ tax to be payed is %f $.", year, income);
}

void outputResultsToFile(const char * filename, const char *outputString)
{
//open output file
 openOutputFile(filename);

// display to outputfile
 writeStringToFile(outputString);
}