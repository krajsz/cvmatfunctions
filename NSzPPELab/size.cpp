#include "size.h"


// todo: throwing exception when getting invalid datas
template <class T>
Size<T>::Size()
{
}

template <class T>
Size<T>::~Size()
{
}

template <class T>
std::string Size<T>::toString() const
{
    std::stringstream ss;
    ss << "Size: width: " << this->getCWidth() << " height: "<< this->getCHeight();
    return ss.str();
}

template<class T>
T& Size<T>::getWidth()
{
   return this->m_first;
}

template <class T>
T& Size<T>::getHeight()
{
    return this->m_second;
}

template<class T>
Size<T>::Size(const T& width, const T& height) : m_valid(false)
{

    if (Utils::checkAllowedType(typeid(T), m_allowedTypes))
    {
        if ((width > 0) && (height > 0) &&
                (width < std::numeric_limits<int>::max()) && (height < std::numeric_limits<int>::max()))
        {
            setWidth(width);
            setHeight(height);
            m_valid = true;
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

template <class T>
Size<T>::Size(const Size &other)
{
    if (other.isValid())
    {
        this->setWidth(other.getCWidth());
        this->setHeight(other.getCHeight());
    }
    else
    {
        std::cout << "Copy failed, the other Size is invalid!" << std::endl;
    }
}

template <class T>
bool Size<T>::isValid() const
{
    return this->m_valid;
}

template <class T>
void Size<T>::setWidth(const T &width)
{
    this->setFirst(width);
}

template <class T>
void Size<T>::setHeight(const T &height)
{
    this->setSecond(height);
}

template <class T>
const T& Size<T>::getCWidth() const
{
    return this->getFirst();
}

template <class T>
const T& Size<T>::getCHeight() const
{
    return this->getSecond();
}

template <class T>
Size<T>& Size<T>::operator =(const Size& other)
{
    this->setWidth(other.getCWidth());
    this->setHeight(other.getCHeight());

    return *this;
}

template class Size<int>;
template class Size<float>;
