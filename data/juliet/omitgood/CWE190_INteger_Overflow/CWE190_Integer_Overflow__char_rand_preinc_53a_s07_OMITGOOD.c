#include "std_testcase.h"
void CWE190_Integer_Overflow__char_rand_preinc_53b_goodG2BSink(char data);
static void goodG2B()
{
    char data;
    data = ' ';
    data = 2;
    CWE190_Integer_Overflow__char_rand_preinc_53b_goodG2BSink(data);
}
void CWE190_Integer_Overflow__char_rand_preinc_53b_goodB2GSink(char data);
static void goodB2G()
{
    char data;
    data = ' ';
    data = (char)RAND32();
    CWE190_Integer_Overflow__char_rand_preinc_53b_goodB2GSink(data);
}
void CWE190_Integer_Overflow__char_rand_preinc_53_good()
{
    goodG2B();
    goodB2G();
}
