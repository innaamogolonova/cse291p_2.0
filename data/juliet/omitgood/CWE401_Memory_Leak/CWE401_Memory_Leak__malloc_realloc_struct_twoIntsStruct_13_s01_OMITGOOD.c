#include "std_testcase.h"
#include <wchar.h>
static void good1()
{
    if(GLOBAL_CONST_FIVE!=5)
    {
        printLine("Benign, fixed string");
    }
    else
    {
        {
            struct _twoIntsStruct * data = (struct _twoIntsStruct *)malloc(100*sizeof(struct _twoIntsStruct));
            if (data == NULL) {exit(-1);}
            struct _twoIntsStruct * tmpData;
            data[0].intOne = 0;
            data[0].intTwo = 0;
            printStructLine((twoIntsStruct *)&data[0]);
            tmpData = (struct _twoIntsStruct *)realloc(data, (130000)*sizeof(struct _twoIntsStruct));
            if (tmpData != NULL)
            {
                data = tmpData;
                data[0].intOne = 1;
                data[0].intTwo = 1;
                printStructLine((twoIntsStruct *)&data[0]);
            }
            free(data);
        }
    }
}
static void good2()
{
    if(GLOBAL_CONST_FIVE==5)
    {
        {
            struct _twoIntsStruct * data = (struct _twoIntsStruct *)malloc(100*sizeof(struct _twoIntsStruct));
            if (data == NULL) {exit(-1);}
            struct _twoIntsStruct * tmpData;
            data[0].intOne = 0;
            data[0].intTwo = 0;
            printStructLine((twoIntsStruct *)&data[0]);
            tmpData = (struct _twoIntsStruct *)realloc(data, (130000)*sizeof(struct _twoIntsStruct));
            if (tmpData != NULL)
            {
                data = tmpData;
                data[0].intOne = 1;
                data[0].intTwo = 1;
                printStructLine((twoIntsStruct *)&data[0]);
            }
            free(data);
        }
    }
}
void CWE401_Memory_Leak__malloc_realloc_struct_twoIntsStruct_13_good()
{
    good1();
    good2();
}
