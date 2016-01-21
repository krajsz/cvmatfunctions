#include "mypair.h"


template <class T>
MyPair<T>::MyPair(const T &first, const T &second): m_first(first), m_second(second), m_data(new T[2])
{
}

template <class T>
void MyPair<T>::setFirst(const T &first)
{
    this->m_first = first;
    m_data[0] = first;
}

template <class T>
void MyPair<T>::setSecond(const T &second)
{
    this->m_second = second;
    m_data[1] = second;
}

template <class T>
const T& MyPair<T>::getFirst() const
{
    return this->m_first;
}

template <class T>
const T& MyPair<T>::getSecond() const
{
    return this->m_second;
}
