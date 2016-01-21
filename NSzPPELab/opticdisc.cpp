#include "opticdisc.h"

OpticDisc::OpticDisc()
{
}

OpticDisc::OpticDisc(const Coordinate<int> &coordinate, int diameter)
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

const Coordinate<int> &OpticDisc::getCoordinate() const
{
    return this->m_coordinate;
}

const int& OpticDisc::getDiameter() const
{
    return this->m_diameter;
}

void OpticDisc::setCoordinate(const Coordinate<int> &coordinate)
{
    this->m_coordinate = coordinate;
}

void OpticDisc::setDiameter(const int &diameter)
{
    this->m_diameter = diameter;
}
