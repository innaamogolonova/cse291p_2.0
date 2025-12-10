#include "std_testcase.h"
void CWE121_Stack_Based_Buffer_Overflow__CWE805_int64_t_declare_loop_05_bad()
{
    int64_t * data;
    int64_t dataBadBuffer[50];
    int64_t dataGoodBuffer[100];
    if(staticTrue)
    {
        data = dataBadBuffer;
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
