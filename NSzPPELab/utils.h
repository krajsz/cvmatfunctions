#ifndef UTILS_H
#define UTILS_H
#pragma once

#include <typeinfo>
#include <vector>
#include <string>

// utility class

class Utils
{
public:
    Utils();

    // checks whether the name of the 'typeinfo' can be found in the 'allowedTypes' vector
    static bool checkAllowedType(const std::type_info& typeinfo, const std::vector<std::string> &allowedTypes);
};

#endif // UTILS_H
