#include "std_testcase.h"
static int badStatic = 0;
static void badSink(int data)
{
    if(badStatic)
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
void CWE122_Heap_Based_Buffer_Overflow__c_CWE129_fscanf_21_bad()
{
    int data;
    data = -1;
    fscanf(stdin, "%d", &data);
    badStatic = 1;
    badSink(data);
}
