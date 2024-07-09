/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Form.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hpatsi <hpatsi@student.hive.fi>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/11 08:57:36 by hpatsi            #+#    #+#             */
/*   Updated: 2024/07/09 21:10:39 by hpatsi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FORM_HPP
# define FORM_HPP

class Form;

# include <string>
# include <iostream>
# include <exception>

# include "Bureaucrat.hpp"

class Form
{
	public:
		Form( void );
		Form( std::string name, int gradeToSign, int gradeToExecute );
		Form( const Form& );
		~Form( void );
		Form& operator=( const Form& );

		std::string getName( void ) const;
		bool getFormSigned( void ) const;
		int getGradeToSign( void ) const;
		int getGradeToExecute( void ) const;

		void beSigned( Bureaucrat& );

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
		bool				formSigned;
		const int			gradeToSign;
		const int			gradeToExecute;
};

std::ostream& operator<<( std::ostream& out, const Form& );

#endif
