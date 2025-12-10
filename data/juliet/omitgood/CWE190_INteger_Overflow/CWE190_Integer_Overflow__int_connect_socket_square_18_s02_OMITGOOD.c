#include "std_testcase.h"
#include <winsock2.h>
#include <windows.h>
#include <direct.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <unistd.h>
#include <math.h>
static void goodB2G()
{
    int data;
    data = 0;
    goto source;
source:
    {
#ifdef _WIN32
        WSADATA wsaData;
        int wsaDataInit = 0;
