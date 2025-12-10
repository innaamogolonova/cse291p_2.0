#include "std_testcase.h"
extern int CWE190_Integer_Overflow__int_max_preinc_22_badGlobal;
void CWE190_Integer_Overflow__int_max_preinc_22_badSink(int data)
{
    if(CWE190_Integer_Overflow__int_max_preinc_22_badGlobal)
    {
        {
            ++data;
            int result = data;
            printIntLine(result);
        }
    }
}
