#include "std_testcase.h"
#include <wchar.h>
void CWE590_Free_Memory_Not_on_Heap__free_long_declare_54e_badSink(long * data)
{
    printLongLine(data[0]);
    free(data);
}
