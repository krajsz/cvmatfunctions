#include "coordinate.h"

// todo: throwing exception when getting invalid datas


template<typename T>
Coordinate::Coordinate(const T& xCoord, const T& yCoord) : valid(false)
{

    if (Utils::checkAllowedType(typeid(T), allowedTypes))
    {
        setX(x);
        setY(y);
    }
    else
    {
        std::cout << "The data type provided is not allowed!" << std::endl;
    }
}

Coordinate::Coordinate(const Coordinate &other)
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

bool Coordinate::isValid() const
{
    return this->valid;
}

template <typename T>
void Coordinate::setX(const T &xCoord)
{
    setFirst(xCoord);
}

template <typename T>
void Coordinate::setY(const T &yCoord)
{
    setSecond(yCoord);
}

template <typename T>
const T& Coordinate::getX() const
{
    return getFirst();
}

template <typename T>
const T& Coordinate::getY() const
{
    return getSecond();
}

Coordinate& Coordinate::operator =(const Coordinate& other)
{
    this->setX(other.getX());
    this->setY(other.getY());

    return *this;
}


