#include "std_testcase.h"
#include <wchar.h>
static void good1()
{
    int k;
    for(k = 0; k < 1; k++)
    {
        {
            twoIntsStruct * data = (twoIntsStruct *)malloc(100*sizeof(twoIntsStruct));
            if (data == NULL) {exit(-1);}
            twoIntsStruct * tmpData;
            data[0].intOne = 0;
            data[0].intTwo = 0;
            printStructLine(&data[0]);
            tmpData = (twoIntsStruct *)realloc(data, (130000)*sizeof(twoIntsStruct));
            if (tmpData != NULL)
            {
                data = tmpData;
                data[0].intOne = 1;
                data[0].intTwo = 1;
                printStructLine(&data[0]);
            }
            free(data);
        }
    }
}
void CWE401_Memory_Leak__malloc_realloc_twoIntsStruct_17_good()
{
    good1();
}
