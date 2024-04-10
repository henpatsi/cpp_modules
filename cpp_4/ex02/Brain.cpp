#include "Brain.hpp"

// CONSTRUCTOR

Brain::Brain(void)
{
	std::cout << "Brain constructed\n";
}

// COPY

Brain::Brain(const Brain& from)
{
	for (int i = 0; i < 100; i++)
		this->ideas[i] = from.ideas[i];
}

// DESTRUCTOR

Brain::~Brain(void)
{
	std::cout << "Brain destroyed\n";
}

// OPERATOR

Brain& Brain::operator=(const Brain& from)
{
	if (this != &from)
	{
		for (int i = 0; i < 100; i++)
			this->ideas[i] = from.ideas[i];
	}
	return *this;
}

// MEMBER FUNCTIONS

void Brain::addIdea( std::string idea )
{
	for (int i = 0; i < 100; i++)
	{
		if (this->ideas[i].empty())
		{
			this->ideas[i] = idea;
			break;
		}
	}
}

void Brain::printIdeas( void )
{
	for (int i = 0; i < 100; i++)
	{
		if (!this->ideas[i].empty())
			std::cout << this->ideas[i] << "\n";
	}
}