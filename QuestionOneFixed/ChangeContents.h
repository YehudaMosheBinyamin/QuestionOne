#ifndef MAX_NAME_LENGTH
#define MAX_NAME_LENGTH 20
#endif // !MAX_NAME_LENGTH
#ifndef MAX_GREETING_LENGTH
#define MAX_GREETING_LENGTH 29
#endif // !MAX_GREETING_NAME_LENGTH
#ifndef MAX_ERROR_MESSAGE_LENGTH
#define MAX_ERROR_MESSAGE_LENGTH 100
#endif // !MAX_ERROR_MESSAGE_LENGTH
#ifndef SUCCESSFUL_OPERATION
#define SUCCESSFUL_OPERATION 1
#endif
#ifndef FAILED_OPERATION
#define FAILED_OPERATION -1
#endif
/**
 * Function that receives a file path, reads a name from the file, and writes to the file the greeting "Hello,<name>!" 
 * Assumption: Maximum  name length in file is MAX_NAME_LENGTH bytes(including null byte) 
 * @param  filePath - a full file path
 * @return If operation succeeds returns SUCCESSFUL_OPERATION, else returns FAILED_OPERATION
 * @attention In case of an error the function reports the error to the user in a user-friendly manner
 */
int ChangeContents(char filePath[]);