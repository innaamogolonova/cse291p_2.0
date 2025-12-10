#include "std_testcase.h"
void CWE190_Integer_Overflow__char_rand_add_01_bad()
{
    char data;
    data = ' ';
    data = (char)RAND32();
    {
        char result = data + 1;
        printHexCharLine(result);
    }
}
