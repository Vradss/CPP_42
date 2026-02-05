#include "Fixed.hpp"

// Constructor por defecto
Fixed::Fixed() : _value(0) {
}

// Constructor con int
Fixed::Fixed(const int value) {
    this->_value = value << _fractionalBits;  // value * 2^8 = value * 256
}

// Constructor con float
Fixed::Fixed(const float value) {
    this->_value = (int)roundf(value * (1 << _fractionalBits));  // roundf(value * 256)
}

// Constructor de copia
Fixed::Fixed(const Fixed& other) {
    *this = other;
}

// Operador de asignación
Fixed& Fixed::operator=(const Fixed& other) {
    if (this != &other) {
        this->_value = other.getRawBits();
    }
    return *this;
}

// Destructor
Fixed::~Fixed() {
}

// Obtener el valor raw
int Fixed::getRawBits(void) const {
    return this->_value;
}

// Establecer el valor raw
void Fixed::setRawBits(int const raw) {
    this->_value = raw;
}

// Convertir a float
float Fixed::toFloat(void) const {
    return (float)this->_value / (1 << _fractionalBits);  // _value / 256.0f
}

// Convertir a int
int Fixed::toInt(void) const {
    return this->_value >> _fractionalBits;  // _value / 256
}

// Operadores de comparación
bool Fixed::operator>(const Fixed& other) const {
    return this->_value > other._value;
}

bool Fixed::operator<(const Fixed& other) const {
    return this->_value < other._value;
}

bool Fixed::operator>=(const Fixed& other) const {
    return this->_value >= other._value;
}

bool Fixed::operator<=(const Fixed& other) const {
    return this->_value <= other._value;
}

bool Fixed::operator==(const Fixed& other) const {
    return this->_value == other._value;
}

bool Fixed::operator!=(const Fixed& other) const {
    return this->_value != other._value;
}

// Operadores aritméticos
Fixed Fixed::operator+(const Fixed& other) const {
    Fixed result;
    result._value = this->_value + other._value;
    return result;
}

Fixed Fixed::operator-(const Fixed& other) const {
    Fixed result;
    result._value = this->_value - other._value;
    return result;
}

Fixed Fixed::operator*(const Fixed& other) const {
    Fixed result;
    // Multiplicar los valores raw y ajustar por los bits fraccionarios
    // (a * b) / 256 para mantener la precisión
    long long temp = (long long)this->_value * (long long)other._value;
    result._value = (int)(temp >> _fractionalBits);
    return result;
}

Fixed Fixed::operator/(const Fixed& other) const {
    Fixed result;
    // Dividir los valores raw y ajustar por los bits fraccionarios
    // (a * 256) / b para mantener la precisión
    long long temp = ((long long)this->_value << _fractionalBits) / (long long)other._value;
    result._value = (int)temp;
    return result;
}

// Pre-incremento (++a)
Fixed& Fixed::operator++(void) {
    this->_value += 1;  // Incrementar en el valor más pequeño representable (1/256)
    return *this;
}

// Pre-decremento (--a)
Fixed& Fixed::operator--(void) {
    this->_value -= 1;  // Decrementar en el valor más pequeño representable (1/256)
    return *this;
}

// Post-incremento (a++)
Fixed Fixed::operator++(int) {
    Fixed temp(*this);
    this->_value += 1;
    return temp;
}

// Post-decremento (a--)
Fixed Fixed::operator--(int) {
    Fixed temp(*this);
    this->_value -= 1;
    return temp;
}

// Funciones estáticas min y max
Fixed& Fixed::min(Fixed& a, Fixed& b) {
    return (a < b) ? a : b;
}

const Fixed& Fixed::min(const Fixed& a, const Fixed& b) {
    return (a < b) ? a : b;
}

Fixed& Fixed::max(Fixed& a, Fixed& b) {
    return (a > b) ? a : b;
}

const Fixed& Fixed::max(const Fixed& a, const Fixed& b) {
    return (a > b) ? a : b;
}

// Sobrecarga del operador de inserción
std::ostream& operator<<(std::ostream& os, const Fixed& fixed) {
    os << fixed.toFloat();
    return os;
}
