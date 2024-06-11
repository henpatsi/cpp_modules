/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AForm.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hpatsi <hpatsi@student.hive.fi>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/11 08:57:36 by hpatsi            #+#    #+#             */
/*   Updated: 2024/06/11 14:49:28 by hpatsi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef AFORM_HPP
# define AFORM_HPP

class AForm;

# include <string>
# include <iostream>
# include <exception>

# include "Bureaucrat.hpp"

class AForm
{
	public:
		AForm( void );
		AForm( std::string name, int gradeToSign, int gradeToExecute );
		AForm( const AForm& );
		virtual ~AForm( void );
		AForm& operator=( const AForm& );

		std::string getName( void ) const;
		bool getFormSigned( void ) const;
		int getGradeToSign( void ) const;
		int getGradeToExecute( void ) const;

		void beSigned( Bureaucrat& );
		void execute( Bureaucrat const & executor ) const;
		virtual void executeFormAction( void ) const = 0;

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
		class FormNotSignedException : public std::exception
		{
			public:
				const char* what() const throw();
		};

	private:
		const std::string	name;
		bool 				formSigned;
		const int 			gradeToSign;
		const int			gradeToExecute;
};

std::ostream& operator<<( std::ostream& out, const AForm& );

#endif
