#include "std_testcase.h"
static int goodB2G1Static = 0;
static int goodB2G2Static = 0;
static int goodG2BStatic = 0;
static void goodB2G1Sink(int data)
{
    if(goodB2G1Static)
    {
        printLine("Benign, fixed string");
    }
    else
    {
        {
            int i;
            int * buffer = (int *)malloc(10 * sizeof(int));
            if (buffer == NULL) {exit(-1);}
            for (i = 0; i < 10; i++)
            {
                buffer[i] = 0;
            }
            if (data >= 0 && data < (10))
            {
                buffer[data] = 1;
                for(i = 0; i < 10; i++)
                {
                    printIntLine(buffer[i]);
                }
            }
            else
            {
                printLine("ERROR: Array index is out-of-bounds");
            }
            free(buffer);
        }
    }
}
static void goodB2G1()
{
    int data;
    data = -1;
    fscanf(stdin, "%d", &data);
    goodB2G1Static = 0;
    goodB2G1Sink(data);
}
static void goodB2G2Sink(int data)
{
    if(goodB2G2Static)
    {
        {
            int i;
            int * buffer = (int *)malloc(10 * sizeof(int));
            if (buffer == NULL) {exit(-1);}
            for (i = 0; i < 10; i++)
            {
                buffer[i] = 0;
            }
            if (data >= 0 && data < (10))
            {
                buffer[data] = 1;
                for(i = 0; i < 10; i++)
                {
                    printIntLine(buffer[i]);
                }
            }
            else
            {
                printLine("ERROR: Array index is out-of-bounds");
            }
            free(buffer);
        }
    }
}
static void goodB2G2()
{
    int data;
    data = -1;
    fscanf(stdin, "%d", &data);
    goodB2G2Static = 1;
    goodB2G2Sink(data);
}
static void goodG2BSink(int data)
{
    if(goodG2BStatic)
    {
        {
            int i;
            int * buffer = (int *)malloc(10 * sizeof(int));
            if (buffer == NULL) {exit(-1);}
            for (i = 0; i < 10; i++)
            {
                buffer[i] = 0;
            }
            if (data >= 0)
            {
                buffer[data] = 1;
                for(i = 0; i < 10; i++)
                {
                    printIntLine(buffer[i]);
                }
            }
            else
            {
                printLine("ERROR: Array index is negative.");
            }
            free(buffer);
        }
    }
}
static void goodG2B()
{
    int data;
    data = -1;
    data = 7;
    goodG2BStatic = 1;
    goodG2BSink(data);
}
void CWE122_Heap_Based_Buffer_Overflow__c_CWE129_fscanf_21_good()
{
    goodB2G1();
    goodB2G2();
    goodG2B();
}
