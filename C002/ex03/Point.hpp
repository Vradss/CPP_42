#ifndef POINT_HPP
#define POINT_HPP

#include "Fixed.hpp"

class Point {
private:
    Fixed const _x;
    Fixed const _y;

public:
    Point();                                    // Constructor por defecto
    Point(const float x, const float y);        // Constructor con dos floats
    Point(const Point& other);                  // Constructor de copia
    Point& operator=(const Point& other);       // Operador de asignación
    ~Point();                                   // Destructor
    
    Fixed getX(void) const;                     // Obtener x
    Fixed getY(void) const;                     // Obtener y
};

#endif
