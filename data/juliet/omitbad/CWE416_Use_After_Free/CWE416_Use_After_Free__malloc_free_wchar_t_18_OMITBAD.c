#include "std_testcase.h"
#include <wchar.h>
void CWE416_Use_After_Free__malloc_free_wchar_t_18_bad()
{
    wchar_t * data;
    data = NULL;
    goto source;
source:
    data = (wchar_t *)malloc(100*sizeof(wchar_t));
    if (data == NULL) {exit(-1);}
    wmemset(data, L'A', 100-1);
    data[100-1] = L'\0';
    free(data);
    goto sink;
sink:
    printWLine(data);
}
