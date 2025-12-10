#include "std_testcase.h"
#include <wchar.h>
extern int CWE121_Stack_Based_Buffer_Overflow__CWE806_char_declare_memmove_22_goodG2B1Global;
extern int CWE121_Stack_Based_Buffer_Overflow__CWE806_char_declare_memmove_22_goodG2B2Global;
char * CWE121_Stack_Based_Buffer_Overflow__CWE806_char_declare_memmove_22_goodG2B1Source(char * data)
{
    if(CWE121_Stack_Based_Buffer_Overflow__CWE806_char_declare_memmove_22_goodG2B1Global)
    {
        printLine("Benign, fixed string");
    }
    else
    {
        memset(data, 'A', 50-1);
        data[50-1] = '\0';
    }
    return data;
}
char * CWE121_Stack_Based_Buffer_Overflow__CWE806_char_declare_memmove_22_goodG2B2Source(char * data)
{
    if(CWE121_Stack_Based_Buffer_Overflow__CWE806_char_declare_memmove_22_goodG2B2Global)
    {
        memset(data, 'A', 50-1);
        data[50-1] = '\0';
    }
    return data;
}
