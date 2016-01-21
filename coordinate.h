#ifndef COORDINATE_H
#define COORDINATE_H
#include <typeinfo>
#include <array>
#include "utils.h"
#include "mypair.h"

template <typename T>
class Coordinate : public MyPair<T>
{
public:
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

    bool valid;

    std::array<3, std::type_info> allowedTypes { typeid(int), typeid(float), typeid(double) };

};

#endif // COORDINATE_H
