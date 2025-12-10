#include "std_testcase.h"
#include <wchar.h>
void CWE415_Double_Free__malloc_free_char_10_bad()
{
    char * data;
    data = NULL;
    if(globalTrue)
    {
        data = (char *)malloc(100*sizeof(char));
        if (data == NULL) {exit(-1);}
        free(data);
    }
    if(globalTrue)
    {
        free(data);
    }
}
