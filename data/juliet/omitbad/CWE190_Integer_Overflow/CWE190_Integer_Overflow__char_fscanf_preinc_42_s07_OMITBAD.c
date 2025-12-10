#include "std_testcase.h"
static char badSource(char data)
{
    fscanf (stdin, "%c", &data);
    return data;
}
void CWE190_Integer_Overflow__char_fscanf_preinc_42_bad()
{
    char data;
    data = ' ';
    data = badSource(data);
    {
        ++data;
        char result = data;
        printHexCharLine(result);
    }
}
