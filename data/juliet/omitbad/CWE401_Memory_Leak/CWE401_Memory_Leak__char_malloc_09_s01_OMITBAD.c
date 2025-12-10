#include "std_testcase.h"
#include <wchar.h>
void CWE401_Memory_Leak__char_malloc_09_bad()
{
    char * data;
    data = NULL;
    if(GLOBAL_CONST_TRUE)
    {
        data = (char *)malloc(100*sizeof(char));
        if (data == NULL) {exit(-1);}
        strcpy(data, "A String");
        printLine(data);
    }
    if(GLOBAL_CONST_TRUE)
    {
        ;
    }
}
