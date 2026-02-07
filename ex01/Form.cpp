#include "Form.hpp"
#include "Bureaucrat.hpp"

std::ostream &operator<<(std::ostream &filestream, Form &Form)
{
    filestream << "SIGNED : " << Form.get_signed() << "\n";
    filestream << "NAME : " << Form.get_name() << "\n";
    filestream << "grade_to_execute : " << Form.get_grade_to_execute() << "\n";
    filestream << "grade_to_sign : " << Form.get_grade_to_sign() << "\n";
    return filestream;
}

int			        Form::get_grade_to_execute(void) {return _grade_to_execute;};
int			        Form::get_grade_to_sign(void) {return _grade_to_sign;};
bool				Form::get_signed(void){return _signed;};
const std::string	Form::get_name(void) {return _name;};

void	Form::beSigned(Bureaucrat &bureaucrat)
{
	if (bureaucrat.getgrade() <= _grade_to_sign)
	{
		_signed = 1;
	}else
		throw Form::GradeTooLowException();
}

const char*	Form::GradeTooHighException::what() const throw()
{
	return "the grade is too high";
}

const char*	Form::GradeTooLowException::what() const throw()
{
	return "the grade is too Low";
}

Form::Form(std::string name, int grade_to_sign, int grade_to_execute) : _name(name), _grade_to_sign(grade_to_sign) , _grade_to_execute(grade_to_execute)
{
	_signed = 0;
	if (grade_to_sign > 150)
	{
		throw Form::GradeTooLowException();
	}
	if (grade_to_sign < 1)
	{
		throw Form::GradeTooHighException();
	}
	if (grade_to_execute > 150)
	{
		throw Form::GradeTooLowException();
	}
	if (grade_to_execute < 1)
	{
		throw Form::GradeTooHighException();
	}
}

Form::Form(const Form& other)
	: _name(other._name),
	  _signed(other._signed),
	  _grade_to_sign(other._grade_to_sign),
	  _grade_to_execute(other._grade_to_execute)
{
}

Form& Form::operator=(const Form& other)
{
	if (this != &other)
		_signed = other._signed;
	return *this;
}

Form::~Form()
{
}
