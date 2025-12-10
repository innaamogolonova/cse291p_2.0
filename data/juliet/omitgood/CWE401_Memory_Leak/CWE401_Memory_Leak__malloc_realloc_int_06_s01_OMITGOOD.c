#include "std_testcase.h"
#include <wchar.h>
static void good1()
{
    if(STATIC_CONST_FIVE!=5)
    {
        printLine("Benign, fixed string");
    }
    else
    {
        {
            int * data = (int *)malloc(100*sizeof(int));
            if (data == NULL) {exit(-1);}
            int * tmpData;
            data[0] = 5;
            printIntLine(data[0]);
            tmpData = (int *)realloc(data, (130000)*sizeof(int));
            if (tmpData != NULL)
            {
                data = tmpData;
                data[0] = 10;
                printIntLine(data[0]);
            }
            free(data);
        }
    }
}
static void good2()
{
    if(STATIC_CONST_FIVE==5)
    {
        {
            int * data = (int *)malloc(100*sizeof(int));
            if (data == NULL) {exit(-1);}
            int * tmpData;
            data[0] = 5;
            printIntLine(data[0]);
            tmpData = (int *)realloc(data, (130000)*sizeof(int));
            if (tmpData != NULL)
            {
                data = tmpData;
                data[0] = 10;
                printIntLine(data[0]);
            }
            free(data);
        }
    }
}
void CWE401_Memory_Leak__malloc_realloc_int_06_good()
{
    good1();
    good2();
}
