#include <iostream>

#include "WasmConst.h"

EM_PORT_API(int) fibonacci(int n)
{
    return n < 2 ? n : fibonacci(n - 1) + fibonacci(n - 2);
}

int    g_int    = 10;
bool   g_bool   = true;
double g_double = 3.14;

EM_PORT_API(int*) getIntPtr()
{
    return &g_int;
}
EM_PORT_API(bool*) getBoolPtr()
{
    return &g_bool;
}
EM_PORT_API(double*) getDoublePtr()
{
    return &g_double;
}

EM_PORT_API(void) printGlobalValue()
{
    std::cout << "cpp: g_int = " << g_int << std::endl;
    std::cout << "cpp: g_bool = " << g_bool << std::endl;
    std::cout << "cpp: g_double = " << g_double << std::endl;
}