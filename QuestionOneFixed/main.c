#include <assert.h>
#include  "ChangeContents.h"

int main(void)
{
    // checking if is given a null argument function works
    assert(ChangeContents(NULL) == FAILED_OPERATION);
    assert(ChangeContents("C:\\NonExistingFolder\\file.txt") == FAILED_OPERATION);
    assert(ChangeContents("C:\\Windows\\nothepad.exe") == FAILED_OPERATION);
    assert(ChangeContents("C:\\Users\\danbe\\Desktop\\NonExistantDocument.txt") == FAILED_OPERATION);
    // Note: if computer's security settings/antivirus settings do not allow changing the contents of files in Desktop,
    // the folowing test will fail and the function will return FAILED_OPERATION 
    assert(ChangeContents("C:\\Users\\danbe\\Desktop\\NewDocument.txt") == SUCCESSFUL_OPERATION);
    assert(ChangeContents("C:\\Windows\\nonexistantfile") == FAILED_OPERATION);
    // This case test be proved by checking the text file
    assert(ChangeContents("\\\\localhost\\C$\\NewFolder\\TextDocument.txt") == SUCCESSFUL_OPERATION);
    return 0;
}