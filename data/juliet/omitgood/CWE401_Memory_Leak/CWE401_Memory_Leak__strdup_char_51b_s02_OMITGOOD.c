#include "std_testcase.h"
#include <wchar.h>
void CWE401_Memory_Leak__strdup_char_51b_goodG2BSink(char * data)
{
    ;
}
void CWE401_Memory_Leak__strdup_char_51b_goodB2GSink(char * data)
{
    free(data);
}
