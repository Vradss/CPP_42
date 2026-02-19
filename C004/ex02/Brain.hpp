#ifndef BRAIN_HPP
#define BRAIN_HPP

#include <iostream>
#include <string>

class Brain {
public:
	static const size_t kIdeasSize = 100;

	Brain();
	Brain(const Brain& other);
	Brain& operator=(const Brain& other);
	~Brain();

	void setIdea(int index, const std::string& idea);
	std::string getIdea(int index) const;

	std::string ideas[100];
};

#endif
