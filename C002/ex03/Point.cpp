#include "Point.hpp"

// Constructor por defecto
Point::Point() : _x(0), _y(0) {
}

// Constructor con dos floats
Point::Point(const float x, const float y) : _x(x), _y(y) {
}

// Constructor de copia
Point::Point(const Point& other) : _x(other._x), _y(other._y) {
}

// Operador de asignación
Point& Point::operator=(const Point& other) {
    // Nota: No podemos asignar a _x y _y porque son const
    // Pero debemos implementar el operador para cumplir con Orthodox Canonical Form
    // En este caso, como los miembros son const, la asignación no tiene efecto real
    // pero el compilador requiere que exista
    (void)other;
    return *this;
}

// Destructor
Point::~Point() {
}

// Obtener x
Fixed Point::getX(void) const {
    return this->_x;
}

// Obtener y
Fixed Point::getY(void) const {
    return this->_y;
}
