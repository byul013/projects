/*/////////////////////////////////////////////////////////////////////////
                        Assignment 1 - Milestone 1
Full Name  : byul yoon
Student ID#: 122034234
Email      : byoon3@myseneca.ca
Section    : ZCC

Authenticity Declaration:
I declare this submission is the result of my own work and has not been
shared with any other student or 3rd party content provider. This submitted
piece of work is entirely of my own creation.
/////////////////////////////////////////////////////////////////////////*/


// ----------------------------------------------------------------------------
// (Do not copy the below)
// ----------------------------------------------------------------------------

// ############################################################################
//
//  Assignment:  1 
//  Milestone:   1
//  Description: Main tester
//
// +---------------------------------------------------------+
// | *** The contents of this file is NOT to be modified *** |    
// +---------------------------------------------------------+
//
//                         HOWEVER....
//
// In the development of your solution, you can...
// -----------------------------------------------
// - Comment the lines of code which call a function you have not yet developed
//   (See each tester function definition to see where you can do this)
// - Uncomment the lines of code previously commented to return the file to its
//   original state so you may fully test your solution.
// 
// ############################################################################
#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>

#include "core.h"


void clearInputBuffer(void)
{
    while (getchar() != '\n')
    {
        ; 
    }
}


void suspend(void)
{
    printf("<ENTER> to continue...");
    clearInputBuffer();
    putchar('\n');
}

int inputInt(void)
{
    char newLine = 'x';
    int value = 0;
    while (newLine != '\n')
    {
        scanf("%d%c", &value, &newLine);
        if (newLine != '\n')
        {
            printf("Error! Input a whole number: ");
            clearInputBuffer();
        }
    }

    return value;
}

int inputIntPositive(void)
{
    int intPositive = 0;
    while (intPositive <= 0)
    {
        intPositive = inputInt();
        if (intPositive <= 0)
        {
            printf("ERROR! Value must be > 0: ");
        }
    }
    return intPositive;
}

int inputIntRange(int lowerBound, int upperBound)
{
    int input = 0;

    do
    {
        input = inputInt();
        if (input < lowerBound || input > upperBound)
        {
            printf("ERROR! Value must be between %d and %d inclusive: ", lowerBound, upperBound);
        }
    } while (input < lowerBound || input > upperBound);

    return input;
}

char inputCharOption(const char optionCstring[])
{
    char input;
    int i, inTheCstring = 0;

    while (inTheCstring == 0)
    {
        scanf("%c", &input);
        for (i = 0; optionCstring[i] != '\0'; i++)
        {
            if (input == optionCstring[i])
            {
                inTheCstring = 1;
            }
        }
        if (inTheCstring == 0)
        {
            printf("ERROR: Character must be one of [%s]: ", optionCstring);
        }
        clearInputBuffer();
    }
    return input;
}

void inputCString(char *aCstring, int minimumNumberofCharacters, int maximumNumberofCharacters)
{
    char input[100] = {0};
    int i, j = 0, inputNumber, inTheRange = 0;

    while (inTheRange == 0)
    {
        inputNumber = 0;
        scanf("%99[^\n]", input);
        for (i = 0; input[i] != '\0'; i++)
        {
            inputNumber++;
        }

        if (inputNumber <= maximumNumberofCharacters && inputNumber >= minimumNumberofCharacters)
        {
            inTheRange = 1;
            while (input[j] != '\0')
            {
                aCstring[j] = input[j];
                j++;
            }
            aCstring[j] = '\0';
        }
        else
        {
            if (maximumNumberofCharacters == minimumNumberofCharacters)
            {
                printf("ERROR: String length must be exactly %d chars: ", maximumNumberofCharacters);
            }
            else if (inputNumber > maximumNumberofCharacters)
            {
                printf("ERROR: String length must be no more than %d chars: ", maximumNumberofCharacters);
            }
            else
            {
                printf("ERROR: String length must be between %d and %d chars: ", minimumNumberofCharacters, maximumNumberofCharacters);
            }
        }
        clearInputBuffer();
    }
}

void displayFormattedPhone(const char *phoneString)
{
    int i, argumentCount = 0, isNotDigit = 0;

    // it is exactly 10 characters long
    if (phoneString != NULL)
    {
        for (i = 0; phoneString[i] != '\0'; i++)
        {
            argumentCount++;
        }
        // only contains digits (0-9)
        for (i = 0; phoneString[i] != '\0'; i++)
        {
            if (phoneString[i] < '0' || phoneString[i] > '9')
            {
                isNotDigit = 1;
            }
        }
    }

    // Print result
    if (argumentCount == 10 && isNotDigit == 0 && phoneString != NULL)
    {
        for (i = 0; phoneString[i] != '\0'; i++)
        {
            if (i == 0)
            {
                printf("(");
            }
            else if (i == 3)
            {
                printf(")");
            }
            else if (i == 6)
            {
                printf("-");
            }
            printf("%c", phoneString[i]);
        }
    }
    else
    {
        printf("(___)___-____");
    }
}