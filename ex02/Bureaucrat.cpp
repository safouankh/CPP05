#include "Bureaucrat.hpp"
#include "Aform.hpp"

void Bureaucrat::signAform(Aform &Aform)
{
	try
	{
		Aform.beSigned(*this);
		std::cout << name << " signed " << Aform.get_name() << '\n';
	}
	catch(const std::exception& e)
	{
		std::cout << name << "  couldn't sign " << Aform.get_name() << " because of " << e.what();
	}
	
}

std::ostream& operator<<(std::ostream &filestream, Bureaucrat &Bureaucrat)
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

void	Bureaucrat::executeAform(const Aform& Aform)
{
	try
	{
		Aform.execute(*this);
	}
	catch(std::exception& e)
	{
		std::cout << name << " couldn't execute " << Aform.get_name() << " because " << e.what() << std::endl;
	}
}
