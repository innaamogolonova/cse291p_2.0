#include "std_testcase.h"
#include <winsock2.h>
#include <windows.h>
#include <direct.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <unistd.h>
static void goodB2G1()
{
    int data;
    data = 0;
    if(GLOBAL_CONST_TRUE)
    {
        {
#ifdef _WIN32
            WSADATA wsaData;
            int wsaDataInit = 0;
