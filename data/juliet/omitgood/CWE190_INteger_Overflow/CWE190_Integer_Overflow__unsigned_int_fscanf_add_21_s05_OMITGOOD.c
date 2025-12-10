#include "std_testcase.h"
static int goodB2G1Static = 0;
static int goodB2G2Static = 0;
static int goodG2BStatic = 0;
static void goodB2G1Sink(unsigned int data)
{
    if(goodB2G1Static)
    {
        printLine("Benign, fixed string");
    }
    else
    {
        if (data < UINT_MAX)
        {
            unsigned int result = data + 1;
            printUnsignedLine(result);
        }
        else
        {
            printLine("data value is too large to perform arithmetic safely.");
        }
    }
}
static void goodB2G1()
{
    unsigned int data;
    data = 0;
    fscanf (stdin, "%u", &data);
    goodB2G1Static = 0;
    goodB2G1Sink(data);
}
static void goodB2G2Sink(unsigned int data)
{
    if(goodB2G2Static)
    {
        if (data < UINT_MAX)
        {
            unsigned int result = data + 1;
            printUnsignedLine(result);
        }
        else
        {
            printLine("data value is too large to perform arithmetic safely.");
        }
    }
}
static void goodB2G2()
{
    unsigned int data;
    data = 0;
    fscanf (stdin, "%u", &data);
    goodB2G2Static = 1;
    goodB2G2Sink(data);
}
static void goodG2BSink(unsigned int data)
{
    if(goodG2BStatic)
    {
        {
            unsigned int result = data + 1;
            printUnsignedLine(result);
        }
    }
}
static void goodG2B()
{
    unsigned int data;
    data = 0;
    data = 2;
    goodG2BStatic = 1;
    goodG2BSink(data);
}
void CWE190_Integer_Overflow__unsigned_int_fscanf_add_21_good()
{
    goodB2G1();
    goodB2G2();
    goodG2B();
}
