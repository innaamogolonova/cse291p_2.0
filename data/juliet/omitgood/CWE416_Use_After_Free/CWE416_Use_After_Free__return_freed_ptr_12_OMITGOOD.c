#include "std_testcase.h"
static void good1()
{
    if(globalReturnsTrueOrFalse())
    {
        {
            char * reversedString = helperGood("GoodSink");
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
void CWE416_Use_After_Free__return_freed_ptr_12_good()
{
    good1();
}
