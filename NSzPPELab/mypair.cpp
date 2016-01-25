#include "mypair.h"

template <class T>
MyPair<T>::MyPair(): m_data(new T[2]{})
{
}

template <class T>
MyPair<T>::~MyPair()
{
    delete[] m_data;
}

template <class T>
std::string MyPair<T>::toString() const
{
    std::stringstream ss;
    ss << "MyPair: " << this->getFirst() << ", "<< this->getSecond();
    return ss.str();
}

template <class T>
void MyPair<T>::setData()
{
    m_data = new T[2] { m_first, m_second };
}

template <class T>
MyPair<T>::MyPair(const T &first, const T &second): m_first(first), m_second(second), m_data(new T[2])
{
}

template <class T>
void MyPair<T>::setFirst(const T &first)
{
    this->m_first = first;
}

template <class T>
void MyPair<T>::setSecond(const T &second)
{
    this->m_second = second;
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

template <class T>
bool operator ==(const MyPair<T>& firstPair, const MyPair<T>& secondPair)
{
    return std::tie(firstPair.getFirst(), firstPair.getSecond()) ==
            std::tie(secondPair.getFirst(), secondPair.getSecond());
}


template class MyPair<int>;
template class MyPair<float>;
template class MyPair<double>;

