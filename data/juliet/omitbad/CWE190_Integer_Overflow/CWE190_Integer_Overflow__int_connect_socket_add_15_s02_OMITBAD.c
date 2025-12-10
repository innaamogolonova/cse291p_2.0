#include "std_testcase.h"
#include <winsock2.h>
#include <windows.h>
#include <direct.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <unistd.h>
void CWE190_Integer_Overflow__int_connect_socket_add_15_bad()
{
    int data;
    data = 0;
    switch(6)
    {
    case 6:
    {
#ifdef _WIN32
        WSADATA wsaData;
        int wsaDataInit = 0;
