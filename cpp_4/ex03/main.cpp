#include "Ice.hpp"
#include "Cure.hpp"
#include "Character.hpp"
#include "MateriaSource.hpp"

int main()
{
	AMateria* ice = new Ice();
	AMateria* cure = new Cure();

	IMateriaSource* src = new MateriaSource();
	// adds ice cure ice cure to materia source
	src->learnMateria(ice);
	src->learnMateria(cure);
	src->learnMateria(ice);
	src->learnMateria(cure);
	src->learnMateria(ice);


	// BASIC TESTS

	std::cout << "Basic tests:\n";
	ICharacter* me = new Character("me");
	ICharacter* bob = new Character("bob");

	AMateria* tmp0 = src->createMateria("ice");
	me->equip(tmp0);
	AMateria* tmp1 = src->createMateria("cure");
	me->equip(tmp1);

	std::cout << "Me only 2 materia set:\n";
	me->use(0, *bob);
	me->use(1, *bob);
	me->use(2, *bob);
	me->use(3, *bob);
	me->use(4, *bob);

	AMateria* tmp2 = src->createMateria("ice");
	me->equip(tmp2);
	AMateria* tmp3 = src->createMateria("cure");
	me->equip(tmp3);

	std::cout << "Me all 4 materia set:\n";
	me->use(0, *bob);
	me->use(1, *bob);
	me->use(2, *bob);
	me->use(3, *bob);
	me->use(4, *bob);

	me->unequip(1);
	delete tmp1;
	me->unequip(3);
	delete tmp3;
	me->unequip(4);
	std::cout << "Me index 1 and 3 unequipped:\n";
	me->use(0, *bob);
	me->use(1, *bob);
	me->use(2, *bob);
	me->use(3, *bob);
	me->use(4, *bob);

	// BAD MATERIA SOURCE TESTS

	std::cout << "\nBad materia source tests:\n";
	IMateriaSource* src_bad = new MateriaSource();
	// ice does not exist in materia source yet
	AMateria* tmp = src_bad->createMateria("ice");
	src_bad->learnMateria(tmp);
	delete tmp;
	// does not add last ice
	src_bad->learnMateria(cure);
	src_bad->learnMateria(cure);
	src_bad->learnMateria(cure);
	src_bad->learnMateria(cure);
	src_bad->learnMateria(ice);

	bob->equip(src_bad->createMateria("ice"));
	bob->equip(src_bad->createMateria("cure"));
	bob->equip(src_bad->createMateria("ice"));
	bob->equip(src_bad->createMateria("cure"));

	std::cout << "Bob 1 (tried to add ice cure ice cure from only cure materia source):\n";
	bob->use(0, *me);
	bob->use(1, *me);
	bob->use(2, *me);
	bob->use(3, *me);
	bob->use(4, *me);


	// COPY TESTS

	std::cout << "\nCopy tests:\n";
	Character original("A");
	original.equip(src->createMateria("ice"));
	original.equip(src->createMateria("cure"));
	std::cout << "Original materia (ice and cure):\n";
	original.use(0, *bob);
	original.use(1, *bob);
	original.use(2, *bob);
	original.use(3, *bob);

	Character copy(original);
	copy.equip(src->createMateria("cure"));
	std::cout << "Copy construct materia (ice cure cure):\n";
	copy.use(0, *bob);
	copy.use(1, *bob);
	copy.use(2, *bob);
	copy.use(3, *bob);

	Character copy2;
	copy2 = original;
	copy2.equip(src->createMateria("ice"));
	std::cout << "Copy equals materia (ice cure ice):\n";
	copy2.use(0, *bob);
	copy2.use(1, *bob);
	copy2.use(2, *bob);
	copy2.use(3, *bob);

	std::cout << "Original materia (ice and cure):\n";
	original.use(0, *bob);
	original.use(1, *bob);
	original.use(2, *bob);
	original.use(3, *bob);


	delete ice;
	delete cure;

	delete src;
	delete src_bad;

	delete bob;
	delete me;

	return 0;
}