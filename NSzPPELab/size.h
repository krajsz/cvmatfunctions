#ifndef SIZE_H
#define SIZE_H
#pragma once

#include <array>
#include <limits>
#include <iostream>

#include "mypair.h"
#include "utils.h"
template<class T>
class Size : public MyPair<T>
{
public:
    Size();
    Size(const T& width, const T& height);
    Size(const Size& other);
    ~Size();
    Size<T> &operator =(const Size& other);

    void setWidth(const T& width);
    void setHeight(const T& height);

    bool isValid() const;

    const T& getCWidth() const;
    const T& getCHeight() const;

    T& getWidth();
    T& getHeight();

    std::string toString() const override;

private:

    bool m_valid;
    std::vector<std::string> m_allowedTypes {typeid(int).name(), typeid(float).name()} ;
};

#endif // SIZE_H
