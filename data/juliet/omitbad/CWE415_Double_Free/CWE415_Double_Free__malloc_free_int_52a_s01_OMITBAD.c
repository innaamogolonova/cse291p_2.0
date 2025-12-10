#include "std_testcase.h"
#include <wchar.h>
void CWE415_Double_Free__malloc_free_int_52b_badSink(int * data);
void CWE415_Double_Free__malloc_free_int_52_bad()
{
    int * data;
    data = NULL;
    data = (int *)malloc(100*sizeof(int));
    if (data == NULL) {exit(-1);}
    free(data);
    CWE415_Double_Free__malloc_free_int_52b_badSink(data);
}
