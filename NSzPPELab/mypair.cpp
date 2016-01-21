#include "mypair.h"


template <class T>
MyPair::MyPair(const T &first, const T &second): m_first(first), m_second(second), m_data(new T[2])
{
}

template <class T>
void MyPair::setFirst(const T &first)
{
    this->m_first = first;
    data[0] = first;
}

template <class T>
void MyPair::setSecond(const T &second)
{
    this->m_second = second;
    data[1] = second;
}

template <class T>
const T& MyPair::getFirst() const
{
    return this->m_first;
}

template <class T>
const T& MyPair::getSecond() const
{
    return this->m_second;
}





