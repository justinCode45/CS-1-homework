#include "../head/Shash.hpp"



unsigned long long  Shash_(const std::string &str)
{
    const char *cstr = str.c_str();
    unsigned long long hash = 5381;
    int c = 0;

    while (c = *cstr++)
        hash = ((hash << 5) + hash) + c; /* hash * 33 + c */

    return hash;
}