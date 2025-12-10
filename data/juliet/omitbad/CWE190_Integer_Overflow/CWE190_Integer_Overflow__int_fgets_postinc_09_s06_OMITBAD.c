#include "std_testcase.h"
void CWE190_Integer_Overflow__int_fgets_postinc_09_bad()
{
    int data;
    data = 0;
    if(GLOBAL_CONST_TRUE)
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
    if(GLOBAL_CONST_TRUE)
    {
        {
            data++;
            int result = data;
            printIntLine(result);
        }
    }
}
