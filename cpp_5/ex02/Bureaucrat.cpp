/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hpatsi <hpatsi@student.hive.fi>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/10 11:20:09 by hpatsi            #+#    #+#             */
/*   Updated: 2024/06/11 11:52:43 by hpatsi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"

// CONSTRUCTOR

Bureaucrat::Bureaucrat(void) : name("")
{
	this->grade = 150;
}

Bureaucrat::Bureaucrat(std::string name, int grade) : name(name)
{
	if (grade > 150)
		throw Bureaucrat::GradeTooLowException();
	else if (grade < 1)
		throw Bureaucrat::GradeTooHighException();
	else
		this->grade = grade;
}

// COPY

Bureaucrat::Bureaucrat(const Bureaucrat& from) : Bureaucrat(from.name, from.grade)
{}

// DESTRUCTOR

Bureaucrat::~Bureaucrat(void)
{}

// OPERATOR

Bureaucrat& Bureaucrat::operator=(const Bureaucrat& from)
{
	if (this != &from)
		this->grade = from.grade;
	return *this;
}

std::ostream& operator<<( std::ostream& out, const Bureaucrat& from ) {
	out << from.getName() << ", bureaucrat grade " << from.getGrade();
	return out;
}

// MEMBER FUNCTIONS

std::string Bureaucrat::getName(void) const
{
	return this->name;
}

int Bureaucrat::getGrade(void) const
{
	return this->grade;
}

void Bureaucrat::incrementGrade( void )
{
	int new_grade = this->grade - 1;
	if (new_grade < 1)
		throw Bureaucrat::GradeTooHighException();
	else
		this->grade = new_grade;
}

void Bureaucrat::decrementGrade( void )
{
	int new_grade = this->grade + 1;
	if (new_grade > 150)
		throw Bureaucrat::GradeTooLowException();
	else
		this->grade = new_grade;
}

void Bureaucrat::signForm(AForm& f)
{
	try
	{
		f.beSigned(*this);
		std::cout << this->name << " signed " << "\"" << f.getName() << "\"" << "\n";
	}
	catch (AForm::GradeTooLowException& e)
	{
		std::cout << this->name << " couldn't sign " << "\"" << f.getName() << "\"" << " because " << e.what() << "\n";
	}
}

void Bureaucrat::executeForm(AForm const & form)
{
	try
	{
		form.execute(*this);
		std::cout << this->name << " executed " << "\"" << form.getName() << "\"" << "\n";
	}
	catch(const std::exception& e)
	{
		std::cout << this->name << " couldn't execute " << "\"" << form.getName() << "\"" << " because " << e.what() << "\n";
	}
	
	
}

// EXCEPTIONS

const char* Bureaucrat::GradeTooHighException::what() const throw()
{
	return "The maximum grade is 1";
}

const char* Bureaucrat::GradeTooLowException::what() const throw()
{
	return "The minimum grade is 150";
}
