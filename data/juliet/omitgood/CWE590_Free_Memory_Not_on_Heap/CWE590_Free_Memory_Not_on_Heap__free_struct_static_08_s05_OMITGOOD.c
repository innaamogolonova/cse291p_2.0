#include "std_testcase.h"
#include <wchar.h>
static void goodG2B1()
{
    twoIntsStruct * data;
    data = NULL;
    if(staticReturnsFalse())
    {
        printLine("Benign, fixed string");
    }
    else
    {
        {
            twoIntsStruct * dataBuffer = (twoIntsStruct *)malloc(100*sizeof(twoIntsStruct));
            if (dataBuffer == NULL)
            {
                printLine("malloc() failed");
                exit(1);
            }
            {
                size_t i;
                for (i = 0; i < 100; i++)
                {
                    dataBuffer[i].intOne = 1;
                    dataBuffer[i].intTwo = 1;
                }
            }
            data = dataBuffer;
        }
    }
    printStructLine(&data[0]);
    free(data);
}
static void goodG2B2()
{
    twoIntsStruct * data;
    data = NULL;
    if(staticReturnsTrue())
    {
        {
            twoIntsStruct * dataBuffer = (twoIntsStruct *)malloc(100*sizeof(twoIntsStruct));
            if (dataBuffer == NULL)
            {
                printLine("malloc() failed");
                exit(1);
            }
            {
                size_t i;
                for (i = 0; i < 100; i++)
                {
                    dataBuffer[i].intOne = 1;
                    dataBuffer[i].intTwo = 1;
                }
            }
            data = dataBuffer;
        }
    }
    printStructLine(&data[0]);
    free(data);
}
void CWE590_Free_Memory_Not_on_Heap__free_struct_static_08_good()
{
    goodG2B1();
    goodG2B2();
}
