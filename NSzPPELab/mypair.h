#ifndef MYPAIR_H
#define MYPAIR_H
#pragma once

template <class T>
class MyPair
{
public:
    MyPair(const T& first, const T& second);
    void setFirst(const T& first);
    void setSecond(const T& second);

    const T& getFirst() const;
    const T& getSecond() const;

private:

    T* m_data;
    T m_first;
    T m_second;
};


#endif // MYPAIR_H
