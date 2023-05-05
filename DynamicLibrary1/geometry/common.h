#ifndef COMMON_H
#define COMMON_H

#define GEOMETRY_API

#ifdef GEOMETRY_MODULE
    #define GEOMETRY_API __declspec(dllexport)
#else
    #define GEOMETRY_API __declspec(dllimport)
#endif

namespace utility
{
GEOMETRY_API void func();
}

#endif  // !COMMON_H
