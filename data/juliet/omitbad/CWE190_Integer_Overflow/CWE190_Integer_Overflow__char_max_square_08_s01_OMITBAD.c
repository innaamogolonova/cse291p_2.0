#include "std_testcase.h"
#include <math.h>
void CWE190_Integer_Overflow__char_max_square_08_bad()
{
    char data;
    data = ' ';
    if(staticReturnsTrue())
    {
        data = CHAR_MAX;
    }
    if(staticReturnsTrue())
    {
        {
            char result = data * data;
            printHexCharLine(result);
        }
    }
}
