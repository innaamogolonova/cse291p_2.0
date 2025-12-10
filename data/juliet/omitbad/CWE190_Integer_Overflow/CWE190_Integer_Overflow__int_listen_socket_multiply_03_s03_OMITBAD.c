#include "std_testcase.h"
#include <winsock2.h>
#include <windows.h>
#include <direct.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <unistd.h>
void CWE190_Integer_Overflow__int_listen_socket_multiply_03_bad()
{
    int data;
    data = 0;
    if(5==5)
    {
        {
#ifdef _WIN32
            WSADATA wsaData;
            int wsaDataInit = 0;
