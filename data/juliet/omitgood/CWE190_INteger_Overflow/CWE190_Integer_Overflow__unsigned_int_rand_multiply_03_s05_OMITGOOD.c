#include "std_testcase.h"
static void goodB2G1()
{
    unsigned int data;
    data = 0;
    if(5==5)
    {
        data = (unsigned int)RAND32();
    }
    if(5!=5)
    {
        printLine("Benign, fixed string");
    }
    else
    {
        if(data > 0)
        {
            if (data < (UINT_MAX/2))
            {
                unsigned int result = data * 2;
                printUnsignedLine(result);
            }
            else
            {
                printLine("data value is too large to perform arithmetic safely.");
            }
        }
    }
}
static void goodB2G2()
{
    unsigned int data;
    data = 0;
    if(5==5)
    {
        data = (unsigned int)RAND32();
    }
    if(5==5)
    {
        if(data > 0)
        {
            if (data < (UINT_MAX/2))
            {
                unsigned int result = data * 2;
                printUnsignedLine(result);
            }
            else
            {
                printLine("data value is too large to perform arithmetic safely.");
            }
        }
    }
}
static void goodG2B1()
{
    unsigned int data;
    data = 0;
    if(5!=5)
    {
        printLine("Benign, fixed string");
    }
    else
    {
        data = 2;
    }
    if(5==5)
    {
        if(data > 0)
        {
            unsigned int result = data * 2;
            printUnsignedLine(result);
        }
    }
}
static void goodG2B2()
{
    unsigned int data;
    data = 0;
    if(5==5)
    {
        data = 2;
    }
    if(5==5)
    {
        if(data > 0)
        {
            unsigned int result = data * 2;
            printUnsignedLine(result);
        }
    }
}
void CWE190_Integer_Overflow__unsigned_int_rand_multiply_03_good()
{
    goodB2G1();
    goodB2G2();
    goodG2B1();
    goodG2B2();
}
