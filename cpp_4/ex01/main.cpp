/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hpatsi <hpatsi@student.hive.fi>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/09 10:17:10 by hpatsi            #+#    #+#             */
/*   Updated: 2024/04/15 08:32:54 by hpatsi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Animal.hpp"
#include "Dog.hpp"
#include "Cat.hpp"
#include "WrongAnimal.hpp"
#include "WrongCat.hpp"

int main()
{
	if (1)
	{
		std::cout << "\033[32m" << "\nOriginal dog:\n" << "\033[0m";
		Dog dog = Dog();
		std::cout << "Ideas:\n";
		dog.getBrain()->addIdea("great idea!");
		dog.getBrain()->addIdea("not so great idea!");
		dog.getBrain()->printIdeas();

		std::cout << "\033[32m" << "\nCopy construct dog:\n" << "\033[0m";
		Dog dogCopy = Dog(dog);
		std::cout << "Ideas (+ wow):\n";
		dogCopy.getBrain()->addIdea("wow!");
		dogCopy.getBrain()->printIdeas();

		std::cout << "\033[32m" << "\nCopy equal dog:\n" << "\033[0m";
		Dog dogCopy2;
		dogCopy2 = dog;
		std::cout << "Ideas (+ amazing):\n";
		dogCopy2.getBrain()->addIdea("amazing!");
		dogCopy2.getBrain()->printIdeas();

		std::cout << "\033[32m" << "\nOriginal dog:\n" << "\033[0m";
		dog.getBrain()->printIdeas();

		std::cout << "\033[32m" << "\nDestruction:\n" << "\033[0m";
	}

	const int amount = 6;
	Animal* animals[amount];

	std::cout << "\033[36m" << "\nDog construction:\n" << "\033[0m";
	for (int i = 0; i < amount / 2; i++)
		animals[i] = new Dog();
	
	std::cout << "\033[36m" << "\nCat construction:\n" << "\033[0m";
	for (int i = amount / 2; i < amount; i++)
		animals[i] = new Cat();

	std::cout << "\033[36m" << "\nSounds:\n" << "\033[0m";
	for (int i = 0; i < amount; i++)
		animals[i]->makeSound();

	std::cout << "\033[36m" << "\nDestruction:\n" << "\033[0m";
	for (int i = 0; i < amount; i++)
		delete animals[i];
	
	return 0;
}