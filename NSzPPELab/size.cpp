#include "size.h"


// todo: throwing exception when getting invalid datas

template<typename T>
Size::Size(const T& width, const T& height) : valid(false)
{

    if (Utils::checkAllowedType(typeid(T), allowedTypes))
    {
        if ((width > 0) && (height > 0))
        {
            setWidth(width);
            setHeight(height);
            valid = true;
        }
        else
        {
            std::cout << "Invalid sizes!" << std::endl;
        }
    }
    else
    {
        std::cout << "The data type provided is not allowed!" << std::endl;
    }
}

Size::Size(const Size &other)
{
    if (other.isValid())
    {
        this->setWidth(other.getWidth());
        this->setHeight(other.getHeight());
    }
    else
    {
        std::cout << "Copy failed, the other Size is invalid!" << std::endl;
    }
}

bool Size::isValid() const
{
    return this->valid;
}

template <typename T>
void Size::setWidth(const T &width)
{
    setFirst(width);
}

template <typename T>
void Size::setHeight(const T &height)
{
    setSecond(height);
}

template <typename T>
const T& Size::getWidth() const
{
    return getFirst();
}

template <typename T>
const T& Size::getHeight() const
{
    return getSecond();
}

Size& Size::operator =(const Size& other)
{
    this->setWidth(other.getWidth());
    this->setHeight(other.getHeight());

    return *this;
}
