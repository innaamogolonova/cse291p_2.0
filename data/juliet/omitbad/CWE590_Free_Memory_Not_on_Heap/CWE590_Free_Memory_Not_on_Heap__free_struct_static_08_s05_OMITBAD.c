#include "std_testcase.h"
#include <wchar.h>
void CWE590_Free_Memory_Not_on_Heap__free_struct_static_08_bad()
{
    twoIntsStruct * data;
    data = NULL;
    if(staticReturnsTrue())
    {
        {
            static twoIntsStruct dataBuffer[100];
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
