#ifndef MYPAIR_H
#define MYPAIR_H
#pragma once

#include <iostream>
#include <sstream>

// base template class to handle datas which

template <class T>
class MyPair
{
public:
    MyPair();
    ~MyPair();
    MyPair(const T& first, const T& second);
    void setFirst(const T& first);
    void setSecond(const T& second);
    void setData();

    const T& getFirst() const;
    const T& getSecond() const;

    virtual std::string toString() const;

protected:

    // pointer to our datas
    T* m_data;

    T m_first;
    T m_second;
};


#endif // MYPAIR_H
