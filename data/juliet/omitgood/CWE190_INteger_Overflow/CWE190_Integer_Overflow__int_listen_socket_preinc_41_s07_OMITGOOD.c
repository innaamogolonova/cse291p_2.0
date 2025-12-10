#include "std_testcase.h"
#include <winsock2.h>
#include <windows.h>
#include <direct.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <unistd.h>
static void goodG2BSink(int data)
{
    {
        ++data;
        int result = data;
        printIntLine(result);
    }
}
static void goodG2B()
{
    int data;
    data = 0;
    data = 2;
    goodG2BSink(data);
}
static void goodB2GSink(int data)
{
    if (data < INT_MAX)
    {
        ++data;
        int result = data;
        printIntLine(result);
    }
    else
    {
        printLine("data value is too large to perform arithmetic safely.");
    }
}
static void goodB2G()
{
    int data;
    data = 0;
    {
#ifdef _WIN32
        WSADATA wsaData;
        int wsaDataInit = 0;
