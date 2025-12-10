#include "std_testcase.h"
#include <wchar.h>
static void goodG2B()
{
    char * data;
    data = NULL;
    goto source;
source:
    data = (char *)malloc(100*sizeof(char));
    if (data == NULL) {exit(-1);}
    data[0] = '\0';
    {
        size_t i;
        char source[100];
        memset(source, 'C', 100-1);
        source[100-1] = '\0';
        for (i = 0; i < 100; i++)
        {
            data[i] = source[i];
        }
        data[100-1] = '\0';
        printLine(data);
        free(data);
    }
}
void CWE122_Heap_Based_Buffer_Overflow__c_CWE805_char_loop_18_good()
{
    goodG2B();
}
