#include "Ice.hpp"
#include "Cure.hpp"
#include "Character.hpp"

int main(void)
{
	AMateria* c = new Cure();
	AMateria* i = new Ice();

	Character bob("Bob");
	Character sue("Sue");

	bob.equip(c);
	bob.equip(i);
	bob.use(0, sue);
	bob.use(1, sue);
}