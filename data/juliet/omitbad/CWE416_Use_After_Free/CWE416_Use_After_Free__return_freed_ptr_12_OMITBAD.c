#include "std_testcase.h"
void CWE416_Use_After_Free__return_freed_ptr_12_bad()
{
    if(globalReturnsTrueOrFalse())
    {
        {
            char * reversedString = helperBad("BadSink");
            printLine(reversedString);
        }
    }
    else
    {
        {
            char * reversedString = helperGood("GoodSink");
            printLine(reversedString);
        }
    }
}
