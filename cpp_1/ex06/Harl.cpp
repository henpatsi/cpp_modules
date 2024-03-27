#include "Harl.hpp"

// PUBLIC

void	Harl::complain( std::string level )
{
	std::string	level_strings[4] = {"DEBUG", "INFO", "WARNING", "ERROR"};
	
	int i;
	for (i = 0; i < 4; i++)
	{
		if (level_strings[i] == level)
			break;
	}
	switch (i)
	{
		case 0:
			debug();
			info();
			warning();
			error();
			break;
		case 1:
			info();
			warning();
			error();
			break;
		case 2:
			warning();
			error();
			break;
		case 3:
			error();
			break;
		default:
			std::cout << "[ Probably complaining about insignificant problems ]\n";
			return;
	}
}

// PRIVATE

void	Harl::debug( void )
{
	std::cout << "[ DEBUG ]\n";
	std::cout << "I love having extra bacon for my 7XL-double-cheese-triple-pickle-special-ketchup burger. I really do!\n";
	std::cout << "\n";
}

void	Harl::info( void )
{
	std::cout << "[ INFO ]\n";
	std::cout << "I cannot believe adding extra bacon costs more money.\n";
	std::cout << "You didn’t put enough bacon in my burger!\n";
	std::cout << "If you did, I wouldn’t be asking for more!\n";
	std::cout << "\n";
}

void	Harl::warning( void )
{
	std::cout << "[ WARNING ]\n";
	std::cout << "I think I deserve to have some extra bacon for free.\n";
	std::cout << "I’ve been coming for years whereas you started working here since last month.\n";
	std::cout << "\n";
}

void	Harl::error( void )
{
	std::cout << "[ ERROR ]\n";
	std::cout << "This is unacceptable! I want to speak to the manager now.\n";
	std::cout << "\n";
}