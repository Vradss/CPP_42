#include <iostream>
#include <string>

int main()
{
    std::string str = "HI THIS IS BRAIN";

    std::string* stringPTR = &str; //declaramos un puntero al str
    std::string& stringREF = str; //declaramos una referencia al str

    std::cout << "Memory addresses " << std::endl;
    std::cout << &str << std::endl; //direccion real del string
    std::cout << stringPTR << std::endl; //direccion que guarda el puntero
    std::cout << &stringREF << std::endl; //direccion del string 

   std::cout << "\nValues " << std::endl; 
    std::cout << str << std::endl;
    std::cout << *stringPTR << std::endl;
    std::cout << stringREF << std::endl;

    return 0;
}
