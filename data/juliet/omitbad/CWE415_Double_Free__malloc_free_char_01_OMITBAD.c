#include "std_testcase.h"
#include <wchar.h>
void CWE415_Double_Free__malloc_free_char_01_bad()
{
    char * data;
    data = NULL;
    data = (char *)malloc(100*sizeof(char));
    if (data == NULL) {exit(-1);}
    free(data);
    free(data);
}
