#include "std_testcase.h"
int CWE190_Integer_Overflow__char_max_preinc_22_badGlobal = 0;
void CWE190_Integer_Overflow__char_max_preinc_22_badSink(char data);
void CWE190_Integer_Overflow__char_max_preinc_22_bad()
{
    char data;
    data = ' ';
    data = CHAR_MAX;
    CWE190_Integer_Overflow__char_max_preinc_22_badGlobal = 1;
    CWE190_Integer_Overflow__char_max_preinc_22_badSink(data);
}
