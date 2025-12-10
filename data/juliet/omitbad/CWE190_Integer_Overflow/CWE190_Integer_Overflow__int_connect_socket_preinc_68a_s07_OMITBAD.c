#include "std_testcase.h"
#include <winsock2.h>
#include <windows.h>
#include <direct.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <unistd.h>
void CWE190_Integer_Overflow__int_connect_socket_preinc_68b_badSink();
void CWE190_Integer_Overflow__int_connect_socket_preinc_68_bad()
{
    int data;
    data = 0;
    {
#ifdef _WIN32
        WSADATA wsaData;
        int wsaDataInit = 0;
