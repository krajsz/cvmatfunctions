#include "opticdisc.h"

OpticDisc::OpticDisc(const Coordinate &coordinate, int diameter)
{
    if (coordinate.isValid())
    {
        setCoordinate(coordinate);
        setDiameter(diameter);
    }
    else
    {
        std::cout << "Cannot set invalid coordinates to optic disc!" << std::endl;
    }
}

const Coordinate& OpticDisc::getCoordinate() const
{
    return this->m_coordinate;
}

const int& OpticDisc::getDiameter() const
{
    return this->m_diameter;
}

void OpticDisc::setCoordinate(const Coordinate &coordinate)
{
    this->m_coordinate = coordinate;
}

void OpticDisc::setDiameter(const int &diameter)
{
    this->m_diameter = diameter;
}
