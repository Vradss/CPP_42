#include <iostream>
#include <fstream>
#include <string>

int main(int argc, char **argv)
{

    if (argc != 4)
    {
        std::cerr << "Error: número incorrecto de argumentos" << std::endl;
        std::cerr << "Uso: ./replace <filename> <s1> <s2>" << std::endl;
        return 1;
    }

    std::string filename = argv[1];
    std::string s1 = argv[2];
    std::string s2 = argv[3];

    if (s1.empty())
    {
        std::cerr << "Error: s1 no puede estar vacío" << std::endl;
        return 1;
    }


    std::ifstream inputFile(filename.c_str());
    if (!inputFile.is_open())
    {
        std::cerr << "Error: no se pudo abrir el archivo '" << filename << "'" << std::endl;
        return 1;
    }

    std::string content;
    std::string line;
    while (std::getline(inputFile, line))
    {
        content += line;
        if (!inputFile.eof())
            content += "\n";
    }
    inputFile.close();


    std::string result;
    size_t pos = 0;
    size_t found = 0;
    
    while ((found = content.find(s1, pos)) != std::string::npos)
    {

        result += content.substr(pos, found - pos);
        result += s2;
        pos = found + s1.length();
    }
    result += content.substr(pos);

    std::string outputFilename = filename + ".replace";

    std::ofstream outputFile(outputFilename.c_str());
    if (!outputFile.is_open())
    {
        std::cerr << "Error: no se pudo crear el archivo '" << outputFilename << "'" << std::endl;
        return 1;
    }

    outputFile << result;
    outputFile.close();

    std::cout << "Reemplazo completado. Archivo creado: " << outputFilename << std::endl;
    return 0;
}
