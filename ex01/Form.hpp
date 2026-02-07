#ifndef FORM_HPP
#define FORM_HPP

#include <iostream>

class Bureaucrat;

class Form
{
	private:
		const std::string	_name;
		bool		_signed;
		const int	_grade_to_sign;
		const int	_grade_to_execute;
	public:
		Form(void) : _name("Form"),_signed(0), _grade_to_sign(10), _grade_to_execute(20) {};
		Form(std::string name, int grade_to_sign, int grade_to_execute);
		Form(const Form& other);
		Form& operator=(const Form& other);
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
		const std::string	get_name(void);
		bool				get_signed(void);
		int			        get_grade_to_sign(void);
		int			        get_grade_to_execute(void);
		void				beSigned(Bureaucrat &bureaucrat);
		~Form();
};

std::ostream &operator<<(std::ostream &filestream, Form &Form);

#endif