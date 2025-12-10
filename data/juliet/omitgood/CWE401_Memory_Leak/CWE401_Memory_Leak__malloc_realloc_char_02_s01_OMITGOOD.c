#include "std_testcase.h"
#include <wchar.h>
static void good1()
{
    if(0)
    {
        printLine("Benign, fixed string");
    }
    else
    {
        {
            char * data = (char *)malloc(100*sizeof(char));
            if (data == NULL) {exit(-1);}
            char * tmpData;
            strcpy(data, "A String");
            printLine(data);
            tmpData = (char *)realloc(data, (130000)*sizeof(char));
            if (tmpData != NULL)
            {
                data = tmpData;
                strcpy(data, "New String");
                printLine(data);
            }
            free(data);
        }
    }
}
static void good2()
{
    if(1)
    {
        {
            char * data = (char *)malloc(100*sizeof(char));
            if (data == NULL) {exit(-1);}
            char * tmpData;
            strcpy(data, "A String");
            printLine(data);
            tmpData = (char *)realloc(data, (130000)*sizeof(char));
            if (tmpData != NULL)
            {
                data = tmpData;
                strcpy(data, "New String");
                printLine(data);
            }
            free(data);
        }
    }
}
void CWE401_Memory_Leak__malloc_realloc_char_02_good()
{
    good1();
    good2();
}
