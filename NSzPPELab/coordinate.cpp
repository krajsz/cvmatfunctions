#include "coordinate.h"

// todo: throwing exception when getting invalid datas
template <class T>
Coordinate<T>::Coordinate()
{
}

template <class T>
Coordinate<T>::~Coordinate()
{
}

template <class T>
std::string Coordinate<T>::toString() const
{
    std::stringstream ss;
    ss << "Coordinate: x: " << this->getX() << " y: " << this->getY();
    return ss.str();
}

template<class T>
Coordinate<T>::Coordinate(const T& xCoord, const T& yCoord) : m_valid(false)
{

    if (Utils::checkAllowedType(typeid(T), m_allowedTypes))
    {
        setX(xCoord);
        setY(yCoord);
        this->setData();
        m_valid = true;
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
        this->m_data = new T(*other.m_data);
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
    this->setFirst(xCoord);
}

template <class T>
void Coordinate<T>::setY(const T &yCoord)
{
    this->setSecond(yCoord);
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
    if (other.isValid())
    {
        this->setX(other.getX());
        this->setY(other.getY());
        this->m_data = new T(*other.m_data);
    }
    else
    {
        std::cout << "Copy assignment failed, other is invalid!";
    }

    return *this;
}

template class Coordinate<int>;
template class Coordinate<float>;
