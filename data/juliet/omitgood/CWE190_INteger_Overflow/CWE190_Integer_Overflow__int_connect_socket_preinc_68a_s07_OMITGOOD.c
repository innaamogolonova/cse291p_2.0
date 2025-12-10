#include "std_testcase.h"
#include <winsock2.h>
#include <windows.h>
#include <direct.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <unistd.h>
void CWE190_Integer_Overflow__int_connect_socket_preinc_68b_goodG2BSink();
void CWE190_Integer_Overflow__int_connect_socket_preinc_68b_goodB2GSink();
static void goodG2B()
{
    int data;
    data = 0;
    data = 2;
    CWE190_Integer_Overflow__int_connect_socket_preinc_68_goodG2BData = data;
    CWE190_Integer_Overflow__int_connect_socket_preinc_68b_goodG2BSink();
}
static void goodB2G()
{
    int data;
    data = 0;
    {
#ifdef _WIN32
        WSADATA wsaData;
        int wsaDataInit = 0;
