#include <stdio.h>
#include  "ChangeContents.h"

int main(void)
{
    ChangeContents("C:\\NonExistingFolder\\file.txt");
    ChangeContents("C:\\Windows\\notepad.exe");
    ChangeContents("C:\\Users\\danbe\\Desktop\\NonExistantDocument.txt");
    ChangeContents("C:\\Users\\danbe\\Desktop\\NewDocument.txt");
    ChangeContents("C:\\Windows\\nonexistantfile");
    ChangeContents("\\\\localhost\\C$\\NewFolder\\TextDocument.txt");
    return 0;
}