#include "std_testcase.h"
#include <wchar.h>
static void goodG2B()
{
    char * data;
    char * *dataPtr1 = &data;
    char * *dataPtr2 = &data;
    data = NULL;
    {
        char * data = *dataPtr1;
        data = (char *)malloc((10+1)*sizeof(char));
        if (data == NULL) {exit(-1);}
        *dataPtr1 = data;
    }
    {
        char * data = *dataPtr2;
        {
            char source[10+1] = SRC_STRING;
            strncpy(data, source, strlen(source) + 1);
            printLine(data);
            free(data);
        }
    }
}
void CWE122_Heap_Based_Buffer_Overflow__c_CWE193_char_ncpy_32_good()
{
    goodG2B();
}
