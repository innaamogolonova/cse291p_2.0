#include "std_testcase.h"
static void goodG2B1()
{
    int64_t * data;
    int64_t dataBadBuffer[50];
    int64_t dataGoodBuffer[100];
    if(staticFalse)
    {
        printLine("Benign, fixed string");
    }
    else
    {
        data = dataGoodBuffer;
    }
    {
        int64_t source[100] = {0};
        {
            size_t i;
            for (i = 0; i < 100; i++)
            {
                data[i] = source[i];
            }
            printLongLongLine(data[0]);
        }
    }
}
static void goodG2B2()
{
    int64_t * data;
    int64_t dataBadBuffer[50];
    int64_t dataGoodBuffer[100];
    if(staticTrue)
    {
        data = dataGoodBuffer;
    }
    {
        int64_t source[100] = {0};
        {
            size_t i;
            for (i = 0; i < 100; i++)
            {
                data[i] = source[i];
            }
            printLongLongLine(data[0]);
        }
    }
}
void CWE121_Stack_Based_Buffer_Overflow__CWE805_int64_t_declare_loop_05_good()
{
    goodG2B1();
    goodG2B2();
}
