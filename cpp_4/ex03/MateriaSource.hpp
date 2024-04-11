#ifndef MATERIASOURCE_HPP
# define MATERIASOURCE_HPP

# include "IMateriaSource.hpp"

class MateriaSource : public IMateriaSource
{
	public:
		MateriaSource( void );
		MateriaSource( const MateriaSource& );
		~MateriaSource( void );
		MateriaSource& operator=( const MateriaSource& );

		void learnMateria(AMateria*);
		AMateria* createMateria(std::string const & type);

	private:
		AMateria* inventory[4];
};

#endif
