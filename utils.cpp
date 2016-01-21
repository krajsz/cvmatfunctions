#include "utils.h"

Utils::Utils()
{
}

bool Utils::checkAllowedType(const std::type_info &typeinfo, const std::array<3, std::type_info> &allowedTypes)
{
    for (const auto& ti : allowedTypes)
    {
        if (ti.name() == typeinfo.name())
        {
            return true;
        }
    }
    return false;
}

