#include "std_testcase.h"
#include <math.h>
void CWE190_Integer_Overflow__short_fscanf_square_08_bad()
{
    short data;
    data = 0;
    if(staticReturnsTrue())
    {
        fscanf (stdin, "%hd", &data);
    }
    if(staticReturnsTrue())
    {
        {
            short result = data * data;
            printIntLine(result);
        }
    }
}
