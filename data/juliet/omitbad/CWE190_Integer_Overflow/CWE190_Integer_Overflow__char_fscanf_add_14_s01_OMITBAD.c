#include "std_testcase.h"
void CWE190_Integer_Overflow__char_fscanf_add_14_bad()
{
    char data;
    data = ' ';
    if(globalFive==5)
    {
        fscanf (stdin, "%c", &data);
    }
    if(globalFive==5)
    {
        {
            char result = data + 1;
            printHexCharLine(result);
        }
    }
}
