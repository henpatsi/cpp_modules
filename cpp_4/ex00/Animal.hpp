/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Animal.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hpatsi <hpatsi@student.hive.fi>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/09 10:16:50 by hpatsi            #+#    #+#             */
/*   Updated: 2024/04/09 12:14:55 by hpatsi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ANIMAL_HPP
# define ANIMAL_HPP

# include <string>
# include <iostream>

class Animal
{
	public:
		Animal( void );
		Animal( const Animal& );
		~Animal( void );
		Animal& operator=( const Animal& );

		virtual void makeSound( void ) const;
		std::string getType( void ) const;

	protected:
		std::string type;
};

#endif
