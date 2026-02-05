#include <iostream>
#include "Point.hpp"
#include "bsp.hpp"

int main( void ) {
    // Test 1: Punto dentro del triángulo
    Point a(0.0f, 0.0f);
    Point b(5.0f, 0.0f);
    Point c(2.5f, 5.0f);
    Point point1(2.5f, 2.0f);  // Punto dentro
    
    std::cout << "Test 1: Punto dentro del triángulo" << std::endl;
    std::cout << "Triángulo: A(0,0), B(5,0), C(2.5,5)" << std::endl;
    std::cout << "Punto: (2.5, 2.0)" << std::endl;
    std::cout << "Resultado: " << (bsp(a, b, c, point1) ? "DENTRO" : "FUERA") << std::endl;
    std::cout << std::endl;
    
    // Test 2: Punto fuera del triángulo
    Point point2(6.0f, 2.0f);  // Punto fuera
    
    std::cout << "Test 2: Punto fuera del triángulo" << std::endl;
    std::cout << "Punto: (6.0, 2.0)" << std::endl;
    std::cout << "Resultado: " << (bsp(a, b, c, point2) ? "DENTRO" : "FUERA") << std::endl;
    std::cout << std::endl;
    
    // Test 3: Punto en un vértice
    Point point3(0.0f, 0.0f);  // Mismo que A
    
    std::cout << "Test 3: Punto en un vértice" << std::endl;
    std::cout << "Punto: (0.0, 0.0) - vértice A" << std::endl;
    std::cout << "Resultado: " << (bsp(a, b, c, point3) ? "DENTRO" : "FUERA") << std::endl;
    std::cout << std::endl;
    
    // Test 4: Punto en un borde
    Point point4(2.5f, 0.0f);  // En el borde AB (mitad del segmento)
    
    std::cout << "Test 4: Punto en un borde" << std::endl;
    std::cout << "Punto: (2.5, 0.0) - en borde AB" << std::endl;
    std::cout << "Resultado: " << (bsp(a, b, c, point4) ? "DENTRO" : "FUERA") << std::endl;
    std::cout << std::endl;
    
    // Test 5: Punto en el centro del triángulo
    Point point5(2.5f, 1.67f);  // Centro aproximado
    
    std::cout << "Test 5: Punto en el centro" << std::endl;
    std::cout << "Punto: (2.5, 1.67)" << std::endl;
    std::cout << "Resultado: " << (bsp(a, b, c, point5) ? "DENTRO" : "FUERA") << std::endl;
    std::cout << std::endl;
    
    // Test 6: Triángulo diferente
    Point d(1.0f, 1.0f);
    Point e(3.0f, 1.0f);
    Point f(2.0f, 3.0f);
    Point point6(2.0f, 2.0f);  // Dentro
    
    std::cout << "Test 6: Otro triángulo" << std::endl;
    std::cout << "Triángulo: D(1,1), E(3,1), F(2,3)" << std::endl;
    std::cout << "Punto: (2.0, 2.0)" << std::endl;
    std::cout << "Resultado: " << (bsp(d, e, f, point6) ? "DENTRO" : "FUERA") << std::endl;
    
    return 0;
}
