#include "std_testcase.h"
extern int CWE190_Integer_Overflow__char_rand_postinc_22_badGlobal;
void CWE190_Integer_Overflow__char_rand_postinc_22_badSink(char data)
{
    if(CWE190_Integer_Overflow__char_rand_postinc_22_badGlobal)
    {
        {
            data++;
            char result = data;
            printHexCharLine(result);
        }
    }
}
