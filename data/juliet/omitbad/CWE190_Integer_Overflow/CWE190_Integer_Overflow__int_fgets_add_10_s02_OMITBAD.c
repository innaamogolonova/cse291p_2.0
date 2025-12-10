#include "std_testcase.h"
void CWE190_Integer_Overflow__int_fgets_add_10_bad()
{
    int data;
    data = 0;
    if(globalTrue)
    {
        {
            char inputBuffer[CHAR_ARRAY_SIZE] = "";
            if (fgets(inputBuffer, CHAR_ARRAY_SIZE, stdin) != NULL)
            {
                data = atoi(inputBuffer);
            }
            else
            {
                printLine("fgets() failed.");
            }
        }
    }
    if(globalTrue)
    {
        {
            int result = data + 1;
            printIntLine(result);
        }
    }
}
