#ifndef COORDINATE_H
#define COORDINATE_H

#pragma once

#include <typeinfo>
#include <iostream>
#include <vector>
#include <array>
#include <sstream>
#include <string>
#include "utils.h"
#include "mypair.h"

// class that handles coordinates, coordinates are just value-pairs,
// there are a few type restrictions

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

    std::string toString() const override;

private:

    // holds whether this coordinate is valid or not
    bool m_valid;

    // the allowed coordinate types
    std::vector<std::string> m_allowedTypes {typeid(int).name(), typeid(float).name(), typeid(double).name()} ;

};

#endif // COORDINATE_H
