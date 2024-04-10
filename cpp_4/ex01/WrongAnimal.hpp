/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   WrongAnimal.hpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hpatsi <hpatsi@student.hive.fi>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/09 10:50:09 by hpatsi            #+#    #+#             */
/*   Updated: 2024/04/09 12:37:07 by hpatsi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef WRONGANIMAL_HPP
# define WRONGANIMAL_HPP

# include <string>
# include <iostream>

class WrongAnimal
{
	public:
		WrongAnimal( void );
		WrongAnimal( const WrongAnimal& );
		virtual ~WrongAnimal( void );
		WrongAnimal& operator=( const WrongAnimal& );

		void makeSound( void ) const;
		std::string getType( void ) const;

	protected:
		std::string type;
};

#endif
