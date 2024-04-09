/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hpatsi <hpatsi@student.hive.fi>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/05 12:49:51 by hpatsi            #+#    #+#             */
/*   Updated: 2024/04/09 09:59:21 by hpatsi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "DiamondTrap.hpp"

int	main(void)
{
	std::cout << "Test constructors:\n";
	DiamondTrap bob("Bob");
	DiamondTrap joe("Joe");
	DiamondTrap sue("Sue");

	std::cout << "\nTest member functions:\n";
	bob.takeDamage(2);
	bob.beRepaired(2);
	bob.attack("Jim");
	bob.highFivesGuys();
	bob.guardGate();
	bob.whoAmI();

	std::cout << "\nTest health functions:\n";
	joe.takeDamage(10);
	joe.takeDamage(89);
	joe.takeDamage(1);

	std::cout << "\nTest energy:\n";
	for (int i = 0; i < 60; i++)
	{
		sue.attack("x");
	}

	std::cout << "\nTest copy:\n";
	DiamondTrap a;
	a = bob;
	DiamondTrap b(joe);

	std::cout << "\nTest destructors:\n";
}