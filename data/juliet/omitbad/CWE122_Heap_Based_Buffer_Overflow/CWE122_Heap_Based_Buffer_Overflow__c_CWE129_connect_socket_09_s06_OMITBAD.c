#include "std_testcase.h"
#include <winsock2.h>
#include <windows.h>
#include <direct.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <unistd.h>
void CWE122_Heap_Based_Buffer_Overflow__c_CWE129_connect_socket_09_bad()
{
    int data;
    data = -1;
    if(GLOBAL_CONST_TRUE)
    {
        {
#ifdef _WIN32
            WSADATA wsaData;
            int wsaDataInit = 0;
