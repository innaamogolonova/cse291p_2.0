#include "std_testcase.h"
#include <wchar.h>
static void goodB2G1()
{
    void * data;
    data = NULL;
    switch(6)
    {
    case 6:
    {
        wchar_t * dataBadBuffer = (wchar_t *)malloc(50*sizeof(wchar_t));
        if (dataBadBuffer == NULL) {exit(-1);}
        wmemset(dataBadBuffer, L'A', 50-1);
        dataBadBuffer[50-1] = L'\0';
        data = (void *)dataBadBuffer;
    }
    break;
    default:
        printLine("Benign, fixed string");
        break;
    }
    switch(8)
    {
    case 7:
        printLine("Benign, fixed string");
        break;
    default:
    {
        size_t dataLen = wcslen((wchar_t *)data);
        void * dest = (void *)calloc(dataLen+1, sizeof(wchar_t));
        if (dest == NULL) {exit(-1);}
        (void)wcscpy(dest, data);
        printWLine((wchar_t *)dest);
        free(dest);
    }
    break;
    }
}
static void goodB2G2()
{
    void * data;
    data = NULL;
    switch(6)
    {
    case 6:
    {
        wchar_t * dataBadBuffer = (wchar_t *)malloc(50*sizeof(wchar_t));
        if (dataBadBuffer == NULL) {exit(-1);}
        wmemset(dataBadBuffer, L'A', 50-1);
        dataBadBuffer[50-1] = L'\0';
        data = (void *)dataBadBuffer;
    }
    break;
    default:
        printLine("Benign, fixed string");
        break;
    }
    switch(7)
    {
    case 7:
    {
        size_t dataLen = wcslen((wchar_t *)data);
        void * dest = (void *)calloc(dataLen+1, sizeof(wchar_t));
        if (dest == NULL) {exit(-1);}
        (void)wcscpy(dest, data);
        printWLine((wchar_t *)dest);
        free(dest);
    }
    break;
    default:
        printLine("Benign, fixed string");
        break;
    }
}
static void goodG2B1()
{
    void * data;
    data = NULL;
    switch(5)
    {
    case 6:
        printLine("Benign, fixed string");
        break;
    default:
    {
        char * dataGoodBuffer = (char *)malloc(50*sizeof(char));
        if (dataGoodBuffer == NULL) {exit(-1);}
        memset(dataGoodBuffer, 'A', 50-1);
        dataGoodBuffer[50-1] = '\0';
        data = (void *)dataGoodBuffer;
    }
    break;
    }
    switch(7)
    {
    case 7:
    {
        size_t dataLen = strlen((char *)data);
        void * dest = (void *)calloc(dataLen+1, 1);
        if (dest == NULL) {exit(-1);}
        (void)strcpy(dest, data);
        printLine((char *)dest);
        free(dest);
    }
    break;
    default:
        printLine("Benign, fixed string");
        break;
    }
}
static void goodG2B2()
{
    void * data;
    data = NULL;
    switch(6)
    {
    case 6:
    {
        char * dataGoodBuffer = (char *)malloc(50*sizeof(char));
        if (dataGoodBuffer == NULL) {exit(-1);}
        memset(dataGoodBuffer, 'A', 50-1);
        dataGoodBuffer[50-1] = '\0';
        data = (void *)dataGoodBuffer;
    }
    break;
    default:
        printLine("Benign, fixed string");
        break;
    }
    switch(7)
    {
    case 7:
    {
        size_t dataLen = strlen((char *)data);
        void * dest = (void *)calloc(dataLen+1, 1);
        if (dest == NULL) {exit(-1);}
        (void)strcpy(dest, data);
        printLine((char *)dest);
        free(dest);
    }
    break;
    default:
        printLine("Benign, fixed string");
        break;
    }
}
void CWE122_Heap_Based_Buffer_Overflow__CWE135_15_good()
{
    goodB2G1();
    goodB2G2();
    goodG2B1();
    goodG2B2();
}
