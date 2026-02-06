#include "Bureaucrat.hpp"
#include "Form.hpp"

void Bureaucrat::signForm(Form &Form)
{
	try
	{
		Form.beSigned(*this);
		std::cout << name << " signed " << Form.get_name() << '\n';
	}
	catch(const std::exception& e)
	{
		std::cout << name << "  couldn't sign " << Form.get_name() << " because of " << e.what();
	}
	
}

std::ostream& operator<<(std::ostream &filestream, Bureaucrat &Bureaucrat)
{
	filestream << Bureaucrat.getname() << ", bureaucrat grade " << Bureaucrat.getgrade() << "\n";
	return filestream;
}

const char*Bureaucrat::GradeTooHighException::what() const throw()
{
	return "the grade is two high";
}

const char* Bureaucrat::GradeTooLowException::what() const throw()
{
	return "the grade is two Low";
}

Bureaucrat::Bureaucrat(std::string _name, int _grade) : name(_name)
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
		return ;
	}
	grade--;
}

void Bureaucrat::decgrade(void)
{
	if (grade >= 150)
	{
		throw Bureaucrat::GradeTooLowException();
		return ;
	}
	grade++;
}

int	Bureaucrat::getgrade(void)
{
	return grade;
}

std::string Bureaucrat::getname(void)
{
	return name;
}
