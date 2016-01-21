#include "coordinate.h"

// todo: throwing exception when getting invalid datas
template <class T>
Coordinate<T>::Coordinate()
{
}

template<class T>
Coordinate<T>::Coordinate(const T& xCoord, const T& yCoord) : m_valid(false)
{

    if (Utils::checkAllowedType(typeid(T), m_allowedTypes))
    {
        setX(xCoord);
        setY(yCoord);
    }
    else
    {
        std::cout << "The data type provided is not allowed!" << std::endl;
    }
}

template <class T>
Coordinate<T>::Coordinate(const Coordinate &other)
{
    if (other.isValid())
    {
        this->setX(other.getX());
        this->setY(other.getY());
    }
    else
    {
        std::cout << "Copy failed, the other coordinate is invalid!" << std::endl;
    }
}

template <class T>
bool Coordinate<T>::isValid() const
{
    return this->m_valid;
}

template <class T>
void Coordinate<T>::setX(const T &xCoord)
{
    setFirst(xCoord);
}

template <class T>
void Coordinate<T>::setY(const T &yCoord)
{
    setSecond(yCoord);
}

template <class T>
const T& Coordinate<T>::getX() const
{
    return this->getFirst();
}

template <class T>
const T& Coordinate<T>::getY() const
{
    return this->getSecond();
}

template <class T>
Coordinate<T> & Coordinate<T>::operator =(const Coordinate& other)
{
    this->setX(other.getX());
    this->setY(other.getY());

    return *this;
}


