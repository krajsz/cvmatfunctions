#ifndef UTILS_H
#define UTILS_H
#pragma once

#include <typeinfo>
#include <array>
class Utils
{
public:
    Utils();
    static bool checkAllowedType(const std::type_info& typeinfo, const std::array<3, std::type_info>& allowedTypes);
};

#endif // UTILS_H
