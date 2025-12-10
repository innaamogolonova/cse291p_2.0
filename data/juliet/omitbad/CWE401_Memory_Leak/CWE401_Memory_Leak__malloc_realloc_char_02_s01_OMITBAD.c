#include "std_testcase.h"
#include <wchar.h>
void CWE401_Memory_Leak__malloc_realloc_char_02_bad()
{
    if(1)
    {
        {
            char * data = (char *)malloc(100*sizeof(char));
            if (data == NULL) {exit(-1);}
            strcpy(data, "A String");
            printLine(data);
            data = (char *)realloc(data, (130000)*sizeof(char));
            if (data != NULL)
            {
                strcpy(data, "New String");
                printLine(data);
                free(data);
            }
        }
    }
}
