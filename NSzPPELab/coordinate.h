#ifndef COORDINATE_H
#define COORDINATE_H

#pragma once

#include <typeinfo>
#include <iostream>
#include <array>
#include "utils.h"
#include "mypair.h"

template <class T>
class Coordinate : public MyPair<T>
{
public:
    Coordinate();
    Coordinate(const T& xCoord, const T& yCoord);
    Coordinate(const Coordinate& other);
    ~Coordinate();
    Coordinate& operator =(const Coordinate& other);

    void setX(const T& x);
    void setY(const T& yCoord);

    bool isValid() const;

    const T& getX() const;
    const T& getY() const;

private:

    bool m_valid;

    std::array<std::type_info, 3> m_allowedTypes { typeid(int), typeid(float), typeid(double) };

};

#endif // COORDINATE_H
