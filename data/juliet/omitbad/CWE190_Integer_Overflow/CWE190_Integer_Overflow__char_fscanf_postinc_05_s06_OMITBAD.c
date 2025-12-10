#include "std_testcase.h"
void CWE190_Integer_Overflow__char_fscanf_postinc_05_bad()
{
    char data;
    data = ' ';
    if(staticTrue)
    {
        fscanf (stdin, "%c", &data);
    }
    if(staticTrue)
    {
        {
            data++;
            char result = data;
            printHexCharLine(result);
        }
    }
}
