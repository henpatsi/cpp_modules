/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hpatsi <hpatsi@student.hive.fi>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/09 10:17:10 by hpatsi            #+#    #+#             */
/*   Updated: 2024/04/11 09:37:40 by hpatsi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Animal.hpp"
#include "Dog.hpp"
#include "Cat.hpp"
#include "WrongAnimal.hpp"
#include "WrongCat.hpp"

int main()
{
	std::cout << "Construction:\n";
	const Animal* meta = new Animal();
	const Animal* j = new Dog();
	const Animal* i = new Cat();
	Cat cat1 = Cat();
	Cat cat2 = Cat(cat1);
	Cat cat3;
	cat3 = cat1;

	std::cout << "\nTypes:\n";
	std::cout << "j: " << j->getType() << " " << std::endl;
	std::cout << "i: " << i->getType() << " " << std::endl;
	std::cout << "cat1: " << cat1.getType() << " " << std::endl;
	std::cout << "cat2: " << cat2.getType() << " " << std::endl;
	std::cout << "cat3: " << cat3.getType() << " " << std::endl;
	std::cout << "meta: " << meta->getType() << " " << std::endl;

	std::cout << "\nMake sound:\n";
	
	std::cout << "j: ";
	j->makeSound();
	std::cout << "i: ";
	i->makeSound();
	std::cout << "cat1: ";
	cat1.makeSound();
	std::cout << "cat2: ";
	cat2.makeSound();
	std::cout << "cat3: ";
	cat3.makeSound();
	std::cout << "meta: ";
	meta->makeSound();

	std::cout << "\nWrong animal test:\n";
	const WrongAnimal* wrongCat = new WrongCat();
	std::cout << wrongCat->getType() << " " << std::endl;
	wrongCat->makeSound();

	std::cout << "\nDelete:\n";
	delete(meta);
	delete(j);
	delete(i);
	delete(wrongCat);

	std::cout << "\nDestruction:\n";
	
	return 0;
}