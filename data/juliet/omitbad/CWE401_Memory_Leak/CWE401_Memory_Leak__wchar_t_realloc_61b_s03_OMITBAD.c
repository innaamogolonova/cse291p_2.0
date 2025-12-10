#include "std_testcase.h"
#include <wchar.h>
wchar_t * CWE401_Memory_Leak__wchar_t_realloc_61b_badSource(wchar_t * data)
{
    data = (wchar_t *)realloc(data, 100*sizeof(wchar_t));
    if (data == NULL) {exit(-1);}
    wcscpy(data, L"A String");
    printWLine(data);
    return data;
}
