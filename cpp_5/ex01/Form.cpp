#include "Form.hpp"

// CONSTRUCTOR

Form::Form(void) : name("Unnamed Form"), gradeToSign(150), gradeToExecute(150)
{
	this->formSigned = false;
}

Form::Form(std::string name, int gradeToSign, int gradeToExecute) : name(name), gradeToSign(gradeToSign), gradeToExecute(gradeToExecute)
{
	this->formSigned = false;
	if (this->gradeToSign > 150 || this->gradeToExecute > 150)
		throw Form::GradeTooLowException();
	else if (this->gradeToSign < 1 || this->gradeToExecute < 1)
		throw Form::GradeTooHighException();
}

// COPY

Form::Form(const Form& from) : Form(from.name, from.gradeToSign, from.gradeToExecute)
{
	this->formSigned = from.formSigned;
}

// DESTRUCTOR

Form::~Form(void)
{
}

// OPERATOR

Form& Form::operator=(const Form& from)
{
	(void) from;
	return *this;
}

std::ostream& operator<<( std::ostream& out, const Form& from ) {
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

std::string Form::getName(void) const
{
	return this->name;
}

bool Form::getFormSigned(void) const
{
	return this->formSigned;
}

int Form::getGradeToSign(void) const
{
	return this->gradeToSign;
}

int Form::getGradeToExecute(void) const
{
	return this->gradeToExecute;
}

void Form::beSigned(Bureaucrat& b)
{
	if (b.getGrade() <= this->gradeToSign)
		this->formSigned = true;
	else
		throw Form::GradeTooLowException();
}

// EXCEPTIONS

const char* Form::GradeTooHighException::what() const throw()
{
	return "grade is too high";
}

const char* Form::GradeTooLowException::what() const throw()
{
	return "grade is too low";
}
