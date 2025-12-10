#include "std_testcase.h"
#include <wchar.h>
void CWE121_Stack_Based_Buffer_Overflow__CWE806_char_alloca_ncat_54b_goodG2BSink(char * data);
static void goodG2B()
{
    char * data;
    char * dataBuffer = (char *)ALLOCA(100*sizeof(char));
    data = dataBuffer;
    memset(data, 'A', 50-1);
    data[50-1] = '\0';
    CWE121_Stack_Based_Buffer_Overflow__CWE806_char_alloca_ncat_54b_goodG2BSink(data);
}
void CWE121_Stack_Based_Buffer_Overflow__CWE806_char_alloca_ncat_54_good()
{
    goodG2B();
}
