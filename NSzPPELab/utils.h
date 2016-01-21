#ifndef UTILS_H
#define UTILS_H
#pragma once

#include <typeinfo>
#include <array>
class Utils
{
public:
    Utils();
    static bool checkAllowedType(const std::type_info& typeinfo, const std::array<std::type_info, 3>& allowedTypes);
};

#endif // UTILS_H
