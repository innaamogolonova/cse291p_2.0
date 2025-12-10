#include "std_testcase.h"
void CWE190_Integer_Overflow__int_fgets_multiply_11_bad()
{
    int data;
    data = 0;
    if(globalReturnsTrue())
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
    if(globalReturnsTrue())
    {
        if(data > 0)
        {
            int result = data * 2;
            printIntLine(result);
        }
    }
}
