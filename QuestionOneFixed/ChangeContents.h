#ifndef MAX_NAME_LENGTH
#define MAX_NAME_LENGTH 20
#endif // !MAX_NAME_LENGTH
#ifndef MAX_GREETING_LENGTH
#define MAX_GREETING_LENGTH 29
#endif // !MAX_GREETING_NAME_LENGTH
#ifndef MAX_ERROR_MESSAGE_LENGTH
#define MAX_ERROR_MESSAGE_LENGTH 100
#endif // !MAX_ERROR_MESSAGE_LENGTH
/**
 * Function that receives a file path, reads a name from the file, and writes to the file the greeting "Hello,<name>!"
 * @param filePath
*/
void ChangeContents(char filePath[]);