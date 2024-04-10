#ifndef IMATERIASOURCE_HPP
# define IMATERIASOURCE_HPP

class IMateriaSource
{
	public:
		IMateriaSource( void );
		IMateriaSource( const IMateriaSource& );
		~IMateriaSource( void );
		IMateriaSource& operator=( const IMateriaSource& );
};

#endif
