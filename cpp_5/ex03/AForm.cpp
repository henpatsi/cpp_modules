/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AForm.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hpatsi <hpatsi@student.hive.fi>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/11 10:50:53 by hpatsi            #+#    #+#             */
/*   Updated: 2024/06/11 11:49:45 by hpatsi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "AForm.hpp"

// CONSTRUCTOR

AForm::AForm(void) : name("Unnamed Form"), gradeToSign(150), gradeToExecute(150)
{
	this->formSigned = false;
}

AForm::AForm(std::string name, int gradeToSign, int gradeToExecute) : name(name), gradeToSign(gradeToSign), gradeToExecute(gradeToExecute)
{
	this->formSigned = false;
	if (this->gradeToSign > 150 || this->gradeToExecute > 150)
		throw AForm::GradeTooLowException();
	else if (this->gradeToSign < 1 || this->gradeToExecute < 1)
		throw AForm::GradeTooHighException();
}

// COPY

AForm::AForm(const AForm& from) : AForm(from.name, from.gradeToSign, from.gradeToExecute)
{
}

// DESTRUCTOR

AForm::~AForm(void)
{
}

// OPERATOR

AForm& AForm::operator=(const AForm& from)
{
	(void) from;
	return *this;
}

std::ostream& operator<<( std::ostream& out, const AForm& from ) {
	out << "Form " << "\"" << from.getName() << "\"";
	out << " requires grade " << from.getGradeToSign() << " to sign";
	out << ", grade " << from.getGradeToExecute() << " to execute";
	if (from.getFormSigned())
		out << ", and is currently signed";
	else
		out << ", and is currently not signed";
	return out;
}

// MEMBER FUNCTIONS

std::string AForm::getName(void) const
{
	return this->name;
}

bool AForm::getFormSigned(void) const
{
	return this->formSigned;
}

int AForm::getGradeToSign(void) const
{
	return this->gradeToSign;
}

int AForm::getGradeToExecute(void) const
{
	return this->gradeToExecute;
}

void AForm::beSigned(Bureaucrat& b)
{
	if (b.getGrade() <= this->gradeToSign)
		this->formSigned = true;
	else
		throw AForm::GradeTooLowException();
}

void AForm::execute(Bureaucrat const & executor) const
{
	if (!this->formSigned)
		throw AForm::FormNotSignedException();
	else if (executor.getGrade() > this->gradeToExecute)
		throw AForm::GradeTooLowException();
	else
		this->executeFormAction();
}

// EXCEPTIONS

const char* AForm::GradeTooHighException::what() const throw()
{
	return "grade is too high";
}

const char* AForm::GradeTooLowException::what() const throw()
{
	return "grade is too low";
}

const char* AForm::FormNotSignedException::what() const throw()
{
	return "form is not signed";
}
