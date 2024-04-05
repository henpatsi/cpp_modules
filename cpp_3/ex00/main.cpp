/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hpatsi <hpatsi@student.hive.fi>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/05 12:49:51 by hpatsi            #+#    #+#             */
/*   Updated: 2024/04/05 14:30:18 by hpatsi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ClapTrap.hpp"

int	main(void)
{
	std::cout << "Creating ClapTraps:\n";
	ClapTrap bob("Bob");
	ClapTrap joe("Joe");
	ClapTrap sue("Sue");
	ClapTrap carl;

	std::cout << "\nEnergy test:\n";
	bob.attack("Joe");
	for (int i = 0; i < 10; i++)
	{
		joe.takeDamage(0);
		bob.attack("Joe");
	}
	bob.takeDamage(100);
	bob.attack("Joe");
	
	std::cout << "\nDeath test:\n";
	joe.takeDamage(10);
	joe.attack("Bob");
	joe.beRepaired(10);

	std::cout << "\nRepair test:\n";
	sue.takeDamage(5);
	sue.beRepaired(4);
	sue.takeDamage(8);
	sue.takeDamage(1);

	std::cout << "\nCopy test:\n";
	ClapTrap sal(carl);
	ClapTrap greg;
	greg = carl;
	sal.takeDamage(10);
	greg.attack("nobody");
	greg.takeDamage(10);
	carl.attack("nobody");
	
	std::cout << "\nDestroy ClapTraps:\n";
	return 0;
}