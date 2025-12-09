#include "std_testcase.h"
#include <wchar.h>
static void goodG2B()
{
    char * data;
    data = NULL;
    data = (char *)malloc(100*sizeof(char));
    if (data == NULL) {exit(-1);}
    free(data);
}
static void goodB2G()
{
    char * data;
    data = NULL;
    data = (char *)malloc(100*sizeof(char));
    if (data == NULL) {exit(-1);}
    free(data);
    ;
}
void CWE415_Double_Free__malloc_free_char_01_good()
{
    goodG2B();
    goodB2G();
}
