#include "std_testcase.h"
void CWE190_Integer_Overflow__int_fscanf_add_08_bad()
{
    int data;
    data = 0;
    if(staticReturnsTrue())
    {
        fscanf(stdin, "%d", &data);
    }
    if(staticReturnsTrue())
    {
        {
            int result = data + 1;
            printIntLine(result);
        }
    }
}
