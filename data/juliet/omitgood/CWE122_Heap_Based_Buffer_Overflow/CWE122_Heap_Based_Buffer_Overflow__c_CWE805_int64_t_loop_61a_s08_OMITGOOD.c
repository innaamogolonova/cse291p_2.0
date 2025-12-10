#include "std_testcase.h"
int64_t * CWE122_Heap_Based_Buffer_Overflow__c_CWE805_int64_t_loop_61b_goodG2BSource(int64_t * data);
static void goodG2B()
{
    int64_t * data;
    data = NULL;
    data = CWE122_Heap_Based_Buffer_Overflow__c_CWE805_int64_t_loop_61b_goodG2BSource(data);
    {
        int64_t source[100] = {0};
        {
            size_t i;
            for (i = 0; i < 100; i++)
            {
                data[i] = source[i];
            }
            printLongLongLine(data[0]);
            free(data);
        }
    }
}
void CWE122_Heap_Based_Buffer_Overflow__c_CWE805_int64_t_loop_61_good()
{
    goodG2B();
}
