#include "std_testcase.h"
void CWE190_Integer_Overflow__char_max_add_15_bad()
{
    char data;
    data = ' ';
    switch(6)
    {
    case 6:
        data = CHAR_MAX;
        break;
    default:
        printLine("Benign, fixed string");
        break;
    }
    switch(7)
    {
    case 7:
    {
        char result = data + 1;
        printHexCharLine(result);
    }
    break;
    default:
        printLine("Benign, fixed string");
        break;
    }
}
