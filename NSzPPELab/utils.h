#ifndef UTILS_H
#define UTILS_H
#pragma once

#include <typeinfo>
#include <vector>
#include <string>
class Utils
{
public:
    Utils();
    static bool checkAllowedType(const std::type_info& typeinfo, const std::vector<std::string> &allowedTypes);
};

#endif // UTILS_H
