#ifndef BUREAUCRAT_HPP
#define BUREAUCRAT_HPP

#include <iostream>

class Bureaucrat
{
	private:
		const std::string name;
		int	grade;
	public:
		Bureaucrat() : name("Bureaucrat"), grade(1) {};
		Bureaucrat(const std::string _name, int _grade);
		Bureaucrat(const Bureaucrat& other);
		Bureaucrat& operator=(const Bureaucrat& other);
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
		int getgrade(void) const;
		std::string	getname(void) const;
		void incgrade(void);
		void decgrade(void);
		~Bureaucrat(void);
};

std::ostream& operator<<(std::ostream &filestream,const Bureaucrat &Bureaucrat);


#endif