#include "std_testcase.h"
static void goodG2B()
{
    twoIntsStruct * data;
    twoIntsStruct * *dataPtr1 = &data;
    twoIntsStruct * *dataPtr2 = &data;
    twoIntsStruct * dataBadBuffer = (twoIntsStruct *)ALLOCA(50*sizeof(twoIntsStruct));
    twoIntsStruct * dataGoodBuffer = (twoIntsStruct *)ALLOCA(100*sizeof(twoIntsStruct));
    {
        twoIntsStruct * data = *dataPtr1;
        data = dataGoodBuffer;
        *dataPtr1 = data;
    }
    {
        twoIntsStruct * data = *dataPtr2;
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
            {
                size_t i;
                for (i = 0; i < 100; i++)
                {
                    data[i] = source[i];
                }
                printStructLine(&data[0]);
            }
        }
    }
}
void CWE121_Stack_Based_Buffer_Overflow__CWE805_struct_alloca_loop_32_good()
{
    goodG2B();
}
