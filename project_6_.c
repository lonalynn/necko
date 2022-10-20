#include "Console_IO_Utility.h"
#include "File_Input_Utility.h"
#include "File_Output_Utility.h"
#include "Arizona_Tax_Utility.h"
#include "StandardConstants.h"

// function prototypes
void createOutputString(char *outputString, int year, double income);
void outputResultsToFile(const char *filename, const char *outputString);

int main()
{

    // Define Variables
    char fileName[STD_STR_LEN] = {0};
    char outputString[HUGE_STR_LEN] = {0};

    // double income, totalIncome, outputIncome;
    double income = 0;
    double totalIncome = 0;
    double outputIncome = 0;
    int year;
    int line = 0;

    // a pointer to the output file's name.
    char outputFilePtr[HUGE_STR_LEN] = {0};

    // Show Title
    // functions: printString, printCharacters, printEndline(s)
    printString("DUMMY TAX CALCULATOR V0.4");
    printEndline();
    printCharacters('=', 27);
    printEndlines(2);

    // Get input
    // Get File name
    // functions: promptForString, printEndline
    promptForString("Enter file name containing income information: ", fileName);
    printEndline();

    // read file
    // open file and check if it was successful
    // function: fopen, print, if
    if (openInputFile(fileName))
    {
        year = readIntegerFromFile();
        line = 1;
        while (!checkForEndOfInputFile())
        {
            if (line % 2 == 0)
            {
                year = readIntegerFromFile();
                line++;
                continue;
            }
            income = readDoubleFromFile();

            totalIncome += income;
            outputIncome = calculateArizonaTax(totalIncome);

            createOutputString(outputString, year, outputIncome);
            sprintf(outputFilePtr, "Tax_Report_%d.txt", year);
            outputResultsToFile(outputFilePtr, outputString);

            line++;
        }

        printString("Arizona Tax for 8 years has been calculated.");
        printEndline();
        printString("The results can be viewed in the report files.");
        printEndline();
    }
    else
    {
        printString("Error opening file.");
        printEndline();
        return 1;
    }

    // End program
    printString("End Program");
    printEndline();
    return 0;
}

void createOutputString(char *outputString, int year, double income)
{
    // this helper function prints (copies) an output string to outputString.
    sprintf(outputString, "For the tax year %d total AZ tax to be payed is $%.2f.", year, income);
}

void outputResultsToFile(const char *filename, const char *outputString)
{
    // open output file
    openOutputFile(filename);

    // display to outputfile
    writeStringToFile(outputString);
    writeEndlineToFile();

    closeOutputFile();
}