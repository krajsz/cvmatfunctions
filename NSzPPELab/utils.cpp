#include "utils.h"

Utils::Utils()
{
}

bool Utils::checkAllowedType(const std::type_info &typeinfo, const std::vector<std::string> &allowedTypes)
{
    for (const auto& ti : allowedTypes)
    {
        if (ti == typeinfo.name())
        {
            return true;
        }
    }
    return false;
}

