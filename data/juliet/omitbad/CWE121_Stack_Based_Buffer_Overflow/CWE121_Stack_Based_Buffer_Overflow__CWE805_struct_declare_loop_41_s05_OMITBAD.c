#include "std_testcase.h"
void CWE121_Stack_Based_Buffer_Overflow__CWE805_struct_declare_loop_41_badSink(twoIntsStruct * data)
{
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
void CWE121_Stack_Based_Buffer_Overflow__CWE805_struct_declare_loop_41_bad()
{
    twoIntsStruct * data;
    twoIntsStruct dataBadBuffer[50];
    twoIntsStruct dataGoodBuffer[100];
    data = dataBadBuffer;
    CWE121_Stack_Based_Buffer_Overflow__CWE805_struct_declare_loop_41_badSink(data);
}
