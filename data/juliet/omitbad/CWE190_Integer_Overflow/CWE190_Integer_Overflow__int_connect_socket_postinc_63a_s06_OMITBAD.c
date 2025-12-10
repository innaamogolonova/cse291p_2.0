#include "std_testcase.h"
#include <winsock2.h>
#include <windows.h>
#include <direct.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <unistd.h>
void CWE190_Integer_Overflow__int_connect_socket_postinc_63b_badSink(int * dataPtr);
void CWE190_Integer_Overflow__int_connect_socket_postinc_63_bad()
{
    int data;
    data = 0;
    {
#ifdef _WIN32
        WSADATA wsaData;
        int wsaDataInit = 0;
