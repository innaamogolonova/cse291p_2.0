#include "std_testcase.h"
#include <wchar.h>
static void goodG2B()
{
    char * data;
    CWE121_Stack_Based_Buffer_Overflow__CWE806_char_declare_ncat_34_unionType myUnion;
    char dataBuffer[100];
    data = dataBuffer;
    memset(data, 'A', 50-1);
    data[50-1] = '\0';
    myUnion.unionFirst = data;
    {
        char * data = myUnion.unionSecond;
        {
            char dest[50] = "";
            strncat(dest, data, strlen(data));
            dest[50-1] = '\0';
            printLine(data);
        }
    }
}
void CWE121_Stack_Based_Buffer_Overflow__CWE806_char_declare_ncat_34_good()
{
    goodG2B();
}
