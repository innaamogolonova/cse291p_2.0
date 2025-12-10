#include "std_testcase.h"
#include <wchar.h>
void CWE121_Stack_Based_Buffer_Overflow__CWE806_char_alloca_ncat_54b_badSink(char * data);
void CWE121_Stack_Based_Buffer_Overflow__CWE806_char_alloca_ncat_54_bad()
{
    char * data;
    char * dataBuffer = (char *)ALLOCA(100*sizeof(char));
    data = dataBuffer;
    memset(data, 'A', 100-1);
    data[100-1] = '\0';
    CWE121_Stack_Based_Buffer_Overflow__CWE806_char_alloca_ncat_54b_badSink(data);
}
