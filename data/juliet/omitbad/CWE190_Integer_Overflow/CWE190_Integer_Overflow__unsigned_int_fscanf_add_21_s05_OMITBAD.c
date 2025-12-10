#include "std_testcase.h"
static int badStatic = 0;
static void badSink(unsigned int data)
{
    if(badStatic)
    {
        {
            unsigned int result = data + 1;
            printUnsignedLine(result);
        }
    }
}
void CWE190_Integer_Overflow__unsigned_int_fscanf_add_21_bad()
{
    unsigned int data;
    data = 0;
    fscanf (stdin, "%u", &data);
    badStatic = 1;
    badSink(data);
}
