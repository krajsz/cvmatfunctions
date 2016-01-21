#ifndef OPTICDISC_H
#define OPTICDISC_H

#include "coordinate.h"
class OpticDisc
{
public:
    OpticDisc(const Coordinate& coordinate, int diameter);
    const Coordinate& getCoordinate() const;
    const int& getDiameter() const;

    void setCoordinate(const Coordinate& coordinate);
    void setDiameter(const int& diameter);

private:

    Coordinate m_coordinate;
    int m_diameter;
};

#endif // OPTICDISC_H
