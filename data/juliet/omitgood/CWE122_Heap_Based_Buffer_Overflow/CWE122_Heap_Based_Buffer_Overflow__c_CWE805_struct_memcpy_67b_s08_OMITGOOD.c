#include "std_testcase.h"
void CWE122_Heap_Based_Buffer_Overflow__c_CWE805_struct_memcpy_67b_goodG2BSink(CWE122_Heap_Based_Buffer_Overflow__c_CWE805_struct_memcpy_67_structType myStruct)
{
    twoIntsStruct * data = myStruct.structFirst;
    {
        twoIntsStruct source[100];
        {
            size_t i;
            for (i = 0; i < 100; i++)
            {
                source[i].intOne = 0;
                source[i].intTwo = 0;
            }
        }
        memcpy(data, source, 100*sizeof(twoIntsStruct));
        printStructLine(&data[0]);
        free(data);
    }
}
