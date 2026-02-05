#include "bsp.hpp"

// Función auxiliar para calcular el producto cruzado en 2D
// Retorna el signo del producto cruzado: positivo, negativo o cero
// El producto cruzado en 2D es: (x1, y1) x (x2, y2) = x1*y2 - x2*y1
static Fixed crossProduct(const Point& a, const Point& b, const Point& point) {
    // Vector AB = B - A
    Fixed abx = b.getX() - a.getX();
    Fixed aby = b.getY() - a.getY();
    
    // Vector AP = P - A
    Fixed apx = point.getX() - a.getX();
    Fixed apy = point.getY() - a.getY();
    
    // Producto cruzado: AB x AP = abx * apy - aby * apx
    return abx * apy - aby * apx;
}

// Función BSP: determina si un punto está dentro de un triángulo
// Usa el método de productos cruzados
bool bsp(Point const a, Point const b, Point const c, Point const point) {
    // Calcular los productos cruzados para cada lado del triángulo
    Fixed cross1 = crossProduct(a, b, point);  // Lado AB
    Fixed cross2 = crossProduct(b, c, point);  // Lado BC
    Fixed cross3 = crossProduct(c, a, point);  // Lado CA
    
    // Si el punto está en un vértice, alguno de los productos cruzados será cero
    // Si el punto está en un borde, alguno de los productos cruzados será cero
    // En ambos casos, retornamos false según las especificaciones
    
    // Verificar si está en un vértice
    if ((point.getX() == a.getX() && point.getY() == a.getY()) ||
        (point.getX() == b.getX() && point.getY() == b.getY()) ||
        (point.getX() == c.getX() && point.getY() == c.getY())) {
        return false;
    }
    
    // Verificar si está en un borde (producto cruzado = 0)
    // Usamos un pequeño epsilon para comparar con cero debido a la precisión fixed-point
    Fixed zero(0);
    if (cross1 == zero || cross2 == zero || cross3 == zero) {
        return false;
    }
    
    // Verificar si todos los productos cruzados tienen el mismo signo
    // Si todos son positivos o todos son negativos, el punto está dentro
    bool sign1 = cross1 > zero;
    bool sign2 = cross2 > zero;
    bool sign3 = cross3 > zero;
    
    // El punto está dentro si todos tienen el mismo signo
    return (sign1 == sign2) && (sign2 == sign3);
}
