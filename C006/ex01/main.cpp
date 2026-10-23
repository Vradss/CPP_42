/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vrads <vrads@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/22 20:40:00 by vrads             #+#    #+#             */
/*   Updated: 2026/10/23 13:27:07 by vrads            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include "Serializer.hpp"

int main()
{
    //Serializer s;

    // 1. Data
    Data data;
    data.id = 42;
    data.name = "Vradsss";
    data.value = 3.14;
    std::cout << "id: " << data.id << " | name: " << data.name << " | value: " << data.value << std::endl;
    std::cout << "&data: " << &data << std::endl;
    std::cout << "----------------------------------------" << std::endl;

    // 2. Serialize: la direccion se convierte en un numero
    uintptr_t raw = Serializer::serialize(&data);
    std::cout << "raw (decimal): " << raw << std::endl;
    std::cout << "raw (hex):     0x" << std::hex << raw << std::dec << std::endl;
    std::cout << "&data:         " << &data << std::endl;
    std::cout << "----------------------------------------" << std::endl;

    // 3. Deserialize: el numero vuelve a ser un puntero
    Data* ptr = Serializer::deserialize(raw);
    std::cout << "ptr:   " << ptr << std::endl;
    std::cout << "&data: " << &data << std::endl;
    std::cout << "ptr == &data: " << (ptr == &data ? "OK" : "KO") << std::endl;
    std::cout << "id: " << ptr->id << " | name: " << ptr->name << " | value: " << ptr->value << std::endl;
    std::cout << "----------------------------------------" << std::endl;

    // 4.modificar a traves de ptr cambia el original
    ptr->id = 99;
    std::cout << "ptr->id = 99 -> data.id: " << data.id << std::endl;
    std::cout << "----------------------------------------" << std::endl;

    // 5, por que uintptr_t y no unsigned int
    std::cout << "sizeof(Data*):        " << sizeof(Data*) << std::endl;
    std::cout << "sizeof(uintptr_t):    " << sizeof(uintptr_t) << std::endl;
    std::cout << "sizeof(unsigned int): " << sizeof(unsigned int) << std::endl;
    return 0;
}
