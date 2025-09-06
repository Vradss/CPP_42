#include <iostream>

class erizo
{
public:
    std::string nombre;
    int edad;

    erizo(std::string n, int e)
    {
        std::cout << "Creando erizo" << std::endl;
        nombre = n;
        edad = e;
    }
    void show()
    {
        std::cout << "Hallo soy " << nombre << " y tengo " << edad << std::endl ; 
    }
};

int main()
{
    erizo person1("Anki", 31);
    erizo person2("Alex", 29);
    person1.show();
    person2.show();
    return 0;

}
