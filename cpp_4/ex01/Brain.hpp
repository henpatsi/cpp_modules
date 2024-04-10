#ifndef BRAIN_HPP
# define BRAIN_HPP

# include <string>
# include <iostream>

class Brain
{
	public:
		Brain( void );
		Brain( const Brain& );
		~Brain( void );
		Brain& operator=( const Brain& );

		void addIdea( std::string idea );
		void printIdeas( void );

	private:
		std::string ideas[100];
};

#endif
