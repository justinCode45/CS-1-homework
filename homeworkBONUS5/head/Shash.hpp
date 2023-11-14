#ifndef _SHASH_HPP
#define _SHASH_HPP

#include <string>
constexpr unsigned long long operator"" _hash(const char *str, size_t len)
{
    unsigned long long hash = 5381;
    int c = 0;

    while (c = *str++)
        hash = ((hash << 5) + hash) + c; /* hash * 33 + c */

    return hash;
}
unsigned long long Shash_(const std::string &str);

#endif // !_SHASH_HPP