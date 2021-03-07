#include <stdio.h>
#include "ChangeContents.h"
#include <errno.h>
#include <string.h>



/**
  * @file ChangeContents.h
  */


int ChangeContents(char filePath[])
{
    if (filePath == NULL)
    {
        return FAILED_OPERATION;
    }

    FILE* fp;
    errno_t errorOpeningCode;
    errorOpeningCode = fopen_s(&fp, filePath, "r");
    //checking success of opening file for reading a name
    if (fp != NULL)
    {
        char greeting[MAX_GREETING_LENGTH] = { 'H','e','l','l','o',',',' ', '\0' };
        char name[MAX_NAME_LENGTH] = { 0 };
        char exclamationMark[] = "!";
        char *readingStatus = fgets(name, MAX_NAME_LENGTH, fp);
        if (readingStatus == NULL) 
        {
            printf_s("There has been an error reading file %s", filePath);
            return FAILED_OPERATION;
        }
        strcat_s(greeting, MAX_GREETING_LENGTH, name);
        strcat_s(greeting, MAX_GREETING_LENGTH, exclamationMark);
        int closeOperation = fclose(fp);
        if (closeOperation == EOF)
        {
            printf_s("Failed to close file %s after reading from it", filePath);
            return FAILED_OPERATION;
        }
        errorOpeningCode = fopen_s(&fp, filePath, "w");
        //checking success of opening file for writing "Hello,<name>!"
        if (fp != NULL)
        {
            int writeToFileStatus = fputs(greeting, fp);
            if (writeToFileStatus == EOF) 
            {
                printf_s("There has been an error writing to file: %s", filePath);
                return FAILED_OPERATION;
            }
            closeOperation = fclose(fp);
            if (closeOperation == EOF)
            {
                printf_s("Failed to close file %s after writing to it", filePath);
                return FAILED_OPERATION;
            }

        }
        //opening file for writing failed 
        else
        {
            char errorMessageBuffer[MAX_ERROR_MESSAGE_LENGTH];
            strerror_s(errorMessageBuffer, MAX_ERROR_MESSAGE_LENGTH, errorOpeningCode);
            printf_s("%s for writing to file with path: %s\n", errorMessageBuffer, filePath);
            return FAILED_OPERATION;

        }
    }
    //opening file for reading failed
    else
    {
        char errorMessageBuffer[MAX_ERROR_MESSAGE_LENGTH];
        strerror_s(errorMessageBuffer, MAX_ERROR_MESSAGE_LENGTH, errorOpeningCode);
        printf_s("%s for reading from file with path: %s\n", errorMessageBuffer, filePath);
        return FAILED_OPERATION;
    }
    return SUCCESSFUL_OPERATION;

}