#include "std_testcase.h"
#include <wchar.h>
static void goodG2B1()
{
    char * data;
    data = NULL;
    if(staticFalse)
    {
        printLine("Benign, fixed string");
    }
    else
    {
        {
            char * dataBuffer = (char *)malloc(100*sizeof(char));
            if (dataBuffer == NULL)
            {
                printLine("malloc() failed");
                exit(1);
            }
            memset(dataBuffer, 'A', 100-1);
            dataBuffer[100-1] = '\0';
            data = dataBuffer;
        }
    }
    printLine(data);
    free(data);
}
static void goodG2B2()
{
    char * data;
    data = NULL;
    if(staticTrue)
    {
        {
            char * dataBuffer = (char *)malloc(100*sizeof(char));
            if (dataBuffer == NULL)
            {
                printLine("malloc() failed");
                exit(1);
            }
            memset(dataBuffer, 'A', 100-1);
            dataBuffer[100-1] = '\0';
            data = dataBuffer;
        }
    }
    printLine(data);
    free(data);
}
void CWE590_Free_Memory_Not_on_Heap__free_char_declare_05_good()
{
    goodG2B1();
    goodG2B2();
}
