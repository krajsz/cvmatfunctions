#ifndef SIZE_H
#define SIZE_H
#include <array>

#include "mypair.h"
#include "utils.h"
template<class T>
class Size : public MyPair<T>
{
public:
    Size(const T& width, const T& height);
    Size(const Size& other);
    ~Size();
    Size& operator =(const Size& other);

    void setWidth(const T& width);
    void setHeight(const T& height);

    bool isValid() const;

    const T& getWidth() const;
    const T& getHeight() const;

private:

    bool valid;
    std::array<3, std::type_info> allowedTypes { typeid(int), typeid(float) };
};

#endif // SIZE_H
