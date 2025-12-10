#include "std_testcase.h"
void CWE190_Integer_Overflow__char_rand_preinc_53b_badSink(char data);
void CWE190_Integer_Overflow__char_rand_preinc_53_bad()
{
    char data;
    data = ' ';
    data = (char)RAND32();
    CWE190_Integer_Overflow__char_rand_preinc_53b_badSink(data);
}
