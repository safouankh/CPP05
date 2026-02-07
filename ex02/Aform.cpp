#include "Aform.hpp"
#include "Bureaucrat.hpp"

std::ostream &operator<<(std::ostream &filestream, Aform &Aform)
{
    filestream << "SIGNED : " << Aform.get_signed() << "\n";
    filestream << "NAME : " << Aform.get_name() << "\n";
    filestream << "grade_to_execute : " << Aform.get_grade_to_execute() << "\n";
    filestream << "grade_to_sign : " << Aform.get_grade_to_sign() << "\n";
    return filestream;
}

int			        Aform::get_grade_to_execute(void) const {return _grade_to_execute;};
int			        Aform::get_grade_to_sign(void) const {return _grade_to_sign;};
bool				Aform::get_signed(void) const {return _signed;};
const std::string	Aform::get_name(void) const {return _name;};

void	Aform::beSigned(Bureaucrat &bureaucrat)
{
	if (bureaucrat.getgrade() <= _grade_to_sign)
	{
		_signed = 1;
	}else
		throw Aform::GradeTooLowException();
}

const char*	Aform::GradeTooHighException::what() const throw()
{
	return "the grade is too high";
}

const char*	Aform::GradeTooLowException::what() const throw()
{
	return "the grade is too Low";
}

Aform::Aform(std::string name, int grade_to_sign, int grade_to_execute) : _name(name), _grade_to_sign(grade_to_sign) , _grade_to_execute(grade_to_execute)
{
	_signed = 0;
	if (grade_to_sign > 150)
		throw Aform::GradeTooLowException();
	if (grade_to_sign < 1)
		throw Aform::GradeTooHighException();
	if (grade_to_execute > 150)
		throw Aform::GradeTooLowException();
	if (grade_to_execute < 1)
		throw Aform::GradeTooHighException();
}

Aform::Aform(const Aform& other)
	: _name(other._name),
	  _signed(other._signed),
	  _grade_to_sign(other._grade_to_sign),
	  _grade_to_execute(other._grade_to_execute)
{
}

Aform& Aform::operator=(const Aform& other)
{
	if (this != &other)
		_signed = other._signed;
	return *this;
}

const char* Aform::FormNotSignedException::what() const throw()
{
    return "form is not signed";
}

Aform::~Aform()
{

}
