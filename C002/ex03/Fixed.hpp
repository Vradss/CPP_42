#ifndef FIXED_HPP
#define FIXED_HPP

#include <iostream>
#include <cmath>

class Fixed {
private:
    int _value;
    static const int _fractionalBits = 8;

public:
    Fixed();                                    // Constructor por defecto
    Fixed(const int value);                     // Constructor con int
    Fixed(const float value);                   // Constructor con float
    Fixed(const Fixed& other);                  // Constructor de copia
    Fixed& operator=(const Fixed& other);       // Operador de asignación
    ~Fixed();                                   // Destructor
    
    int getRawBits(void) const;                 // Obtener el valor raw
    void setRawBits(int const raw);             // Establecer el valor raw
    
    float toFloat(void) const;                  // Convertir a float
    int toInt(void) const;                      // Convertir a int
    
    // Operadores de comparación
    bool operator>(const Fixed& other) const;
    bool operator<(const Fixed& other) const;
    bool operator>=(const Fixed& other) const;
    bool operator<=(const Fixed& other) const;
    bool operator==(const Fixed& other) const;
    bool operator!=(const Fixed& other) const;
    
    // Operadores aritméticos
    Fixed operator+(const Fixed& other) const;
    Fixed operator-(const Fixed& other) const;
    Fixed operator*(const Fixed& other) const;
    Fixed operator/(const Fixed& other) const;
    
    // Operadores de incremento/decremento (pre-incremento)
    Fixed& operator++(void);
    Fixed& operator--(void);
    
    // Operadores de incremento/decremento (post-incremento)
    Fixed operator++(int);
    Fixed operator--(int);
    
    // Funciones estáticas min y max
    static Fixed& min(Fixed& a, Fixed& b);
    static const Fixed& min(const Fixed& a, const Fixed& b);
    static Fixed& max(Fixed& a, Fixed& b);
    static const Fixed& max(const Fixed& a, const Fixed& b);
};

// Sobrecarga del operador de inserción
std::ostream& operator<<(std::ostream& os, const Fixed& fixed);

#endif
