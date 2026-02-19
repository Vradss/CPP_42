#ifndef WRONGANIMAL_HPP
#define WRONGANIMAL_HPP

#include <iostream>
#include <string>

class WrongAnimal {
protected:
	std::string type;

public:
	WrongAnimal();
	WrongAnimal(const WrongAnimal& other);
	WrongAnimal& operator=(const WrongAnimal& other);
	// Destructor no virtual a propósito: delete por WrongAnimal* no llama ~WrongCat() (puede causar leaks).
	~WrongAnimal();

	std::string getType() const;
	void makeSound() const;
};

#endif
