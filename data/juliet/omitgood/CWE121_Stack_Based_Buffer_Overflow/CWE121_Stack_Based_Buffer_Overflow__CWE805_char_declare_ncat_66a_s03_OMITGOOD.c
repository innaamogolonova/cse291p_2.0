#include "std_testcase.h"
#include <wchar.h>
void CWE121_Stack_Based_Buffer_Overflow__CWE805_char_declare_ncat_66b_goodG2BSink(char * dataArray[]);
static void goodG2B()
{
    char * data;
    char * dataArray[5];
    char dataBadBuffer[50];
    char dataGoodBuffer[100];
    data = dataGoodBuffer;
    data[0] = '\0';
    dataArray[2] = data;
    CWE121_Stack_Based_Buffer_Overflow__CWE805_char_declare_ncat_66b_goodG2BSink(dataArray);
}
void CWE121_Stack_Based_Buffer_Overflow__CWE805_char_declare_ncat_66_good()
{
    goodG2B();
}
