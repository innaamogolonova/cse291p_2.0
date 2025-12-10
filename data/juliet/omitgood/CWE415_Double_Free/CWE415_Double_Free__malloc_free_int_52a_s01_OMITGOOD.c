#include "std_testcase.h"
#include <wchar.h>
void CWE415_Double_Free__malloc_free_int_52b_goodG2BSink(int * data);
static void goodG2B()
{
    int * data;
    data = NULL;
    data = (int *)malloc(100*sizeof(int));
    if (data == NULL) {exit(-1);}
    CWE415_Double_Free__malloc_free_int_52b_goodG2BSink(data);
}
void CWE415_Double_Free__malloc_free_int_52b_goodB2GSink(int * data);
static void goodB2G()
{
    int * data;
    data = NULL;
    data = (int *)malloc(100*sizeof(int));
    if (data == NULL) {exit(-1);}
    free(data);
    CWE415_Double_Free__malloc_free_int_52b_goodB2GSink(data);
}
void CWE415_Double_Free__malloc_free_int_52_good()
{
    goodG2B();
    goodB2G();
}
