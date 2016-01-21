#ifndef OPTICDISC_H
#define OPTICDISC_H

#include <iostream>
#include "coordinate.h"
class OpticDisc
{
public:
    OpticDisc();
    OpticDisc(const Coordinate<int>& coordinate, int diameter);
    const Coordinate<int>& getCoordinate() const;
    const int& getDiameter() const;

    void setCoordinate(const Coordinate<int>& coordinate);
    void setDiameter(const int& diameter);

    std::string toString() const;
private:

    Coordinate<int> m_coordinate;
    int m_diameter;
};

#endif // OPTICDISC_H
