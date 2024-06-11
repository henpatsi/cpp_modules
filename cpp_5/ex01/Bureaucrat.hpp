/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.hpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hpatsi <hpatsi@student.hive.fi>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/10 11:20:07 by hpatsi            #+#    #+#             */
/*   Updated: 2024/06/11 09:46:36 by hpatsi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BUREAUCRAT_HPP
# define BUREAUCRAT_HPP

class Bureaucrat;

# include <string>
# include <iostream>
# include <exception>

# include "Form.hpp"

class Bureaucrat
{
	public:
		Bureaucrat( void );
		Bureaucrat( std::string name, int grade );
		Bureaucrat( const Bureaucrat& );
		~Bureaucrat( void );
		Bureaucrat& operator=( const Bureaucrat& );

		std::string getName( void ) const;
		int getGrade( void ) const;
		void incrementGrade( void );
		void decrementGrade( void );

		void signForm( Form& );

		class GradeTooHighException : public std::exception
		{
			public:
				const char* what() const throw();
		};
		class GradeTooLowException : public std::exception
		{
			public:
				const char* what() const throw();
		};

	private:
		const std::string	name;
		int					grade;
};

std::ostream& operator<<( std::ostream& out, const Bureaucrat& );

#endif
