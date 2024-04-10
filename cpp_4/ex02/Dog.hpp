/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Dog.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hpatsi <hpatsi@student.hive.fi>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/09 10:31:44 by hpatsi            #+#    #+#             */
/*   Updated: 2024/04/10 13:02:39 by hpatsi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef DOG_HPP
# define DOG_HPP

# include "Animal.hpp"
# include "Brain.hpp"

class Dog : public Animal
{
	public:
		Dog( void );
		Dog( const Dog& );
		~Dog( void );
		Dog& operator=( const Dog& );

		void makeSound( void ) const;
		Brain* getBrain( void );

	private:
		Brain* brain;
};

#endif
