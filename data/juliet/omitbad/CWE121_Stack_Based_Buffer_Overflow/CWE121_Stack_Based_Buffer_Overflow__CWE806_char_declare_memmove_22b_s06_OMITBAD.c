#include "std_testcase.h"
#include <wchar.h>
extern int CWE121_Stack_Based_Buffer_Overflow__CWE806_char_declare_memmove_22_badGlobal;
char * CWE121_Stack_Based_Buffer_Overflow__CWE806_char_declare_memmove_22_badSource(char * data)
{
    if(CWE121_Stack_Based_Buffer_Overflow__CWE806_char_declare_memmove_22_badGlobal)
    {
        memset(data, 'A', 100-1);
        data[100-1] = '\0';
    }
    return data;
}
