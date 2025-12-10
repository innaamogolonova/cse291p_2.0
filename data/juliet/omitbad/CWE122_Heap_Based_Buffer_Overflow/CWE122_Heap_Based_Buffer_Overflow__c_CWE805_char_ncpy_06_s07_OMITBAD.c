#include "std_testcase.h"
#include <wchar.h>
void CWE122_Heap_Based_Buffer_Overflow__c_CWE805_char_ncpy_06_bad()
{
    char * data;
    data = NULL;
    if(STATIC_CONST_FIVE==5)
    {
        data = (char *)malloc(50*sizeof(char));
        if (data == NULL) {exit(-1);}
        data[0] = '\0';
    }
    {
        char source[100];
        memset(source, 'C', 100-1);
        source[100-1] = '\0';
        strncpy(data, source, 100-1);
        data[100-1] = '\0';
        printLine(data);
        free(data);
    }
}
