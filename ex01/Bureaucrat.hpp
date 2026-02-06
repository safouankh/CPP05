#ifndef BUREAUCRAT_HPP
#define BUREAUCRAT_HPP

#include <iostream>

class Form;

class Bureaucrat
{
	private:
		const std::string name;
		int	grade;
	public:
		Bureaucrat() : name("Bureaucrat"), grade(1) {};
		Bureaucrat(std::string _name, int _grade);
		class GradeTooHighException : public std::exception
		{
			public:
				virtual const char* what() const throw();
		};
		class GradeTooLowException : public std::exception
		{
			public :
				virtual const char* what() const throw();
		};
		int getgrade(void);
		std::string	getname(void);
		void incgrade(void);
		void decgrade(void);
		void signForm(Form &Form);
};

std::ostream& operator<<(std::ostream &filestream, Bureaucrat &Bureaucrat);


#endif