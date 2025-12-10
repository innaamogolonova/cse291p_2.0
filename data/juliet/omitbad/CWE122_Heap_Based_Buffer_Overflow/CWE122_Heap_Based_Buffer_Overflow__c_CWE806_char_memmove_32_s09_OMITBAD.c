#include "std_testcase.h"
#include <wchar.h>
void CWE122_Heap_Based_Buffer_Overflow__c_CWE806_char_memmove_32_bad()
{
    char * data;
    char * *dataPtr1 = &data;
    char * *dataPtr2 = &data;
    data = (char *)malloc(100*sizeof(char));
    if (data == NULL) {exit(-1);}
    {
        char * data = *dataPtr1;
        memset(data, 'A', 100-1);
        data[100-1] = '\0';
        *dataPtr1 = data;
    }
    {
        char * data = *dataPtr2;
        {
            char dest[50] = "";
            memmove(dest, data, strlen(data)*sizeof(char));
            dest[50-1] = '\0';
            printLine(data);
            free(data);
        }
    }
}
