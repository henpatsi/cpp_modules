#include "Ice.hpp"
#include "Cure.hpp"
#include "Character.hpp"
#include "MateriaSource.hpp"

int main()
{
	AMateria* ice = new Ice();
	AMateria* cure = new Cure();
	AMateria* tmp;

	IMateriaSource* src = new MateriaSource();
	// adds ice cure ice cure to materia source
	src->learnMateria(ice);
	src->learnMateria(cure);
	src->learnMateria(ice);
	src->learnMateria(cure);


	ICharacter* me = new Character("me");
	ICharacter* bob = new Character("bob");

	tmp = src->createMateria("ice");
	me->equip(tmp);
	tmp = src->createMateria("cure");
	me->equip(tmp);

	std::cout << "Me 1 (only 2 materia set):\n";
	me->use(0, *bob);
	me->use(1, *bob);
	me->use(2, *bob);
	me->use(3, *bob);
	me->use(4, *bob);

	tmp = src->createMateria("ice");
	me->equip(tmp);
	tmp = src->createMateria("cure");
	me->equip(tmp);

	std::cout << "Me 2 (all 4 materia set):\n";
	me->use(0, *bob);
	me->use(1, *bob);
	me->use(2, *bob);
	me->use(3, *bob);
	me->use(4, *bob);


	IMateriaSource* src_bad = new MateriaSource();
	// ice does not exist in materia source yet
	tmp = src_bad->createMateria("ice");
	src_bad->learnMateria(tmp);
	delete tmp;
	// does not add last ice
	src_bad->learnMateria(cure);
	src_bad->learnMateria(cure);
	src_bad->learnMateria(cure);
	src_bad->learnMateria(cure);
	src_bad->learnMateria(ice);

	tmp = src_bad->createMateria("ice");
	bob->equip(tmp);
	tmp = src_bad->createMateria("cure");
	bob->equip(tmp);
	tmp = src_bad->createMateria("ice");
	bob->equip(tmp);
	tmp = src_bad->createMateria("cure");
	bob->equip(tmp);

	std::cout << "Bob 1 (tried to add ice cure ice cure):\n";
	bob->use(0, *me);
	bob->use(1, *me);
	bob->use(2, *me);
	bob->use(3, *me);
	bob->use(4, *me);


	delete ice;
	delete cure;

	delete src;
	delete src_bad;

	delete bob;
	delete me;

	return 0;
}