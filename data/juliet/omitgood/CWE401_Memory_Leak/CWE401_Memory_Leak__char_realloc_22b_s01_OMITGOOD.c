#include "std_testcase.h"
#include <wchar.h>
extern int CWE401_Memory_Leak__char_realloc_22_goodB2G1Global;
extern int CWE401_Memory_Leak__char_realloc_22_goodB2G2Global;
extern int CWE401_Memory_Leak__char_realloc_22_goodG2BGlobal;
void CWE401_Memory_Leak__char_realloc_22_goodB2G1Sink(char * data)
{
    if(CWE401_Memory_Leak__char_realloc_22_goodB2G1Global)
    {
        printLine("Benign, fixed string");
    }
    else
    {
        free(data);
    }
}
void CWE401_Memory_Leak__char_realloc_22_goodB2G2Sink(char * data)
{
    if(CWE401_Memory_Leak__char_realloc_22_goodB2G2Global)
    {
        free(data);
    }
}
void CWE401_Memory_Leak__char_realloc_22_goodG2BSink(char * data)
{
    if(CWE401_Memory_Leak__char_realloc_22_goodG2BGlobal)
    {
        ;
    }
}
