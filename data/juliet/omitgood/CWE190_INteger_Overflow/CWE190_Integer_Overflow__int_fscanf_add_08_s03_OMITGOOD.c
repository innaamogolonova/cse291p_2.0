#include "std_testcase.h"
static void goodB2G1()
{
    int data;
    data = 0;
    if(staticReturnsTrue())
    {
        fscanf(stdin, "%d", &data);
    }
    if(staticReturnsFalse())
    {
        printLine("Benign, fixed string");
    }
    else
    {
        if (data < INT_MAX)
        {
            int result = data + 1;
            printIntLine(result);
        }
        else
        {
            printLine("data value is too large to perform arithmetic safely.");
        }
    }
}
static void goodB2G2()
{
    int data;
    data = 0;
    if(staticReturnsTrue())
    {
        fscanf(stdin, "%d", &data);
    }
    if(staticReturnsTrue())
    {
        if (data < INT_MAX)
        {
            int result = data + 1;
            printIntLine(result);
        }
        else
        {
            printLine("data value is too large to perform arithmetic safely.");
        }
    }
}
static void goodG2B1()
{
    int data;
    data = 0;
    if(staticReturnsFalse())
    {
        printLine("Benign, fixed string");
    }
    else
    {
        data = 2;
    }
    if(staticReturnsTrue())
    {
        {
            int result = data + 1;
            printIntLine(result);
        }
    }
}
static void goodG2B2()
{
    int data;
    data = 0;
    if(staticReturnsTrue())
    {
        data = 2;
    }
    if(staticReturnsTrue())
    {
        {
            int result = data + 1;
            printIntLine(result);
        }
    }
}
void CWE190_Integer_Overflow__int_fscanf_add_08_good()
{
    goodB2G1();
    goodB2G2();
    goodG2B1();
    goodG2B2();
}
