#include "std_testcase.h"
#include <wchar.h>
void CWE122_Heap_Based_Buffer_Overflow__c_CWE193_char_loop_32_bad()
{
    char * data;
    char * *dataPtr1 = &data;
    char * *dataPtr2 = &data;
    data = NULL;
    {
        char * data = *dataPtr1;
        data = (char *)malloc(10*sizeof(char));
        if (data == NULL) {exit(-1);}
        *dataPtr1 = data;
    }
    {
        char * data = *dataPtr2;
        {
            char source[10+1] = SRC_STRING;
            size_t i, sourceLen;
            sourceLen = strlen(source);
            for (i = 0; i < sourceLen + 1; i++)
            {
                data[i] = source[i];
            }
            printLine(data);
            free(data);
        }
    }
}
