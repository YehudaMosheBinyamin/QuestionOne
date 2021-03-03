#include <stdio.h>
#include "ChangeContents.h"
#include <errno.h>
#include <string.h>
#include <stdlib.h>
#include "ChangeContents.h"
void ChangeContents(char filePath[])
{
    FILE* fp;
    errno_t errorOpeningCode;
    errorOpeningCode = fopen_s(&fp, filePath, "r");
    if (fp != NULL)//checking success of opening file for reading a name
    {
        char greeting[MAX_GREETING_LENGTH] = { 'H','e','l','l','o',',',' ', '\0' };
        char name[MAX_NAME_LENGTH] = { 0 };
        char exclamationMark[] = "!";
        int readFromFile = fscanf_s(fp, "%s", name, sizeof(name));

        if (readFromFile == EOF)
        {
            printf_s("There has been an error reading file %s", filePath);
        }

        strcat_s(greeting, MAX_GREETING_LENGTH, name);
        strcat_s(greeting, MAX_GREETING_LENGTH, exclamationMark);
        int closeOperation = fclose(fp);

        if (closeOperation == EOF)
        {
            printf_s("Failed to close file %s after reading from it", filePath);
            exit(-1);
        }

        errorOpeningCode = fopen_s(&fp, filePath, "w");

        if (fp != NULL)//checking success of opening file for writing "Hello,<name>!"
        {
            int writeToFile = fprintf_s(fp, "%s", greeting);
            if (writeToFile < 0)
            {
                printf_s("There has been an error writing to file: %s", filePath);
                return;
            }
            closeOperation = fclose(fp);
            if (closeOperation == EOF)
            {
                printf_s("Failed to close file %s after writing to it", filePath);
                exit(-1);
            }

        }

        else//opening file for writing failed 
        {
            char errorMessageBuffer[MAX_ERROR_MESSAGE_LENGTH];
            strerror_s(errorMessageBuffer, MAX_ERROR_MESSAGE_LENGTH, errorOpeningCode);
            printf_s("%s for writing to file with path: %s\n", errorMessageBuffer, filePath);
            return;
        }
    }

    else//opening file for reading failed
    {
        char errorMessageBuffer[MAX_ERROR_MESSAGE_LENGTH];
        strerror_s(errorMessageBuffer, MAX_ERROR_MESSAGE_LENGTH, errorOpeningCode);
        printf_s("%s for reading from file with path: %s\n", errorMessageBuffer, filePath);
        return;
    }
    return;

}


