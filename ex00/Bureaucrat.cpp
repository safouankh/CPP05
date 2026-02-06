#include "Bureaucrat.hpp"

std::ostream& operator<<(std::ostream &filestream,const Bureaucrat &Bureaucrat)
{
	filestream << Bureaucrat.getname() << ", bureaucrat grade " << Bureaucrat.getgrade() << "\n";
	return filestream;
}

const char*Bureaucrat::GradeTooHighException::what() const throw()
{
	return "the grade is too high";
}

const char* Bureaucrat::GradeTooLowException::what() const throw()
{
	return "the grade is too Low";
}

Bureaucrat::Bureaucrat(const std::string _name, int _grade) : name(_name)
{
	if (_grade > 150)
		throw Bureaucrat::GradeTooLowException();
	if (_grade < 1)
		throw Bureaucrat::GradeTooHighException();
	grade = _grade;
}

void Bureaucrat::incgrade(void)
{
	if (grade <= 1)
	{
		throw Bureaucrat::GradeTooHighException();
	}
	grade--;
}

void Bureaucrat::decgrade(void)
{
	if (grade >= 150)
	{
		throw Bureaucrat::GradeTooLowException();
	}
	grade++;
}

int	Bureaucrat::getgrade(void) const
{
	return grade;
}

std::string Bureaucrat::getname(void) const
{
	return name;
}

Bureaucrat::~Bureaucrat(void)
{
	std::cout << "destructor called\n";
}