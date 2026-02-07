#ifndef Aform_HPP
#define Aform_HPP

#include <iostream>

class Bureaucrat;

class Aform
{
	private:
		const std::string	_name;
		bool		_signed;
		const int	_grade_to_sign;
		const int	_grade_to_execute;
	public:
		Aform(void) : _name("Aform"),_signed(0), _grade_to_sign(10), _grade_to_execute(20) {};
		Aform(std::string name, int grade_to_sign, int grade_to_execute);
		class GradeTooLowException : public std::exception
		{
			public :
				virtual const char* what() const throw();
		};
		class GradeTooHighException : public std::exception
		{
			public:
				virtual const char* what() const throw();
		};
		class FormNotSignedException : public std::exception
		{
			public:
				virtual const char* what() const throw();
		};
		virtual void		execute(Bureaucrat const & executor) const = 0;
		const std::string	get_name(void) const;
		bool				get_signed(void) const;
		int			        get_grade_to_sign(void) const;
		int			        get_grade_to_execute(void) const;
		void				beSigned(Bureaucrat &bureaucrat);
		virtual				~Aform();
};

std::ostream &operator<<(std::ostream &filestream, Aform &Aform);

#endif