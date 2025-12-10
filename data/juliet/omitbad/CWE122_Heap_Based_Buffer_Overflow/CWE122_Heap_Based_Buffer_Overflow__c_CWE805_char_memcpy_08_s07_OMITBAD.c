#include "std_testcase.h"
#include <wchar.h>
void CWE122_Heap_Based_Buffer_Overflow__c_CWE805_char_memcpy_08_bad()
{
    char * data;
    data = NULL;
    if(staticReturnsTrue())
    {
        data = (char *)malloc(50*sizeof(char));
        if (data == NULL) {exit(-1);}
        data[0] = '\0';
    }
    {
        char source[100];
        memset(source, 'C', 100-1);
        source[100-1] = '\0';
        memcpy(data, source, 100*sizeof(char));
        data[100-1] = '\0';
        printLine(data);
        free(data);
    }
}
