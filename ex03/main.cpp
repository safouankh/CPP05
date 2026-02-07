#include "Bureaucrat.hpp"
#include "Aform.hpp"
#include "PresidentialPardonForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "ShrubberyCreationForm.hpp"
#include "Intern.hpp"

int main(void)
{
	{
		std::cout << "\033[34mConstructing\033[0m" << std::endl;
		Bureaucrat *a = new Bureaucrat();
		Intern *z = new Intern();
		Aform *b = z->makeForm("SomeRandomForm", "Clown");
		b = z->makeForm("presidential pardon", "Clown");
		// Aform *b = new PresidentialPardonForm("Clown");
		// Aform *c = new RobotomyRequestForm("Bender");
		// Aform *d = new ShrubberyCreationForm("Christmas");
		std::cout << std::endl;

		std::cout << "\033[34mTesting\033[0m" << std::endl;
		std::cout << *a;
		std::cout << *b;
		std::cout << std::endl;

		try
		{
			b->beSigned(*a);
			// b->execute(*a);
		}
		catch(Aform::GradeTooLowException &e)
		{
			std::cerr << "\033[33m" << a->getname() << " was not able to sign " << b->get_name() << ": " << e.what() << "\033[0m" << std::endl;
		}

		std::cout << std::endl;
		std::cout << *b;
		std::cout << std::endl;

		std::cout << "\033[34mDeconstructing\033[0m" << std::endl;
		delete a;
		delete b;
		delete z;
		std::cout << std::endl;
	}
	std::cout << "--------------------------------------------------------------------------------------------------------------" << std::endl;
	{
		std::cout << std::endl;

		std::cout << "\033[34mConstructing\033[0m" << std::endl;
		Bureaucrat *a = new Bureaucrat("Assistant", 145);
		Bureaucrat *b = new Bureaucrat("CEO", 1);
		Aform *c = new PresidentialPardonForm("some dude");
		// Aform *d = new Aform(*c);
		// Aform *d = new Aform("Rent Contract", 140, 100); // you are not able to construct an abstract class here
		std::cout << std::endl;

		std::cout << "\033[34mTesting\033[0m" << std::endl;
		std::cout << *a;
		std::cout << *b;
		std::cout << *c;
		std::cout << std::endl;

		// Try to execute before signing
		try
		{
			c->execute(*b);
		}
		catch (Aform::FormNotSignedException &e)
		{
			std::cerr << "\033[33m" << a->getname() << " was not able to execute the Aform " << c->get_name() << ": " << e.what() << "\033[0m" << std::endl;
		}
		std::cout << std::endl;
		// Assistant signs the Form
		try
		{
			c->beSigned(*a);
			// a->signAform(*c);
		}
		catch(Aform::GradeTooLowException &e)
		{
			std::cerr << "\033[33m" << a->getname() << " was not able to sign the Aform " << c->get_name() << ": " << e.what() << "\033[0m" << std::endl;
		}

		// CEO signs the Form
		std::cout << std::endl;
		std::cout << *c;
		std::cout << std::endl;
		try
		{
			c->beSigned(*b);
			// b->signAform(*c);
		}
		// catch(Aform::GradeTooLowException &e)
		catch(Aform::GradeTooLowException &e)
		{
			std::cerr << "\033[33m" << b->getname() << " was not able to sign the Aform " << c->get_name() << ": " << e.what() << "\033[0m" << std::endl;
		}
		std::cout << std::endl;
		std::cout << *c;
		std::cout << std::endl;

		// try signing the from again
		std::cout << std::endl;
		b->signAform(*c);
		std::cout << std::endl;

		// execute the Form from assistant
		try
		{
			c->execute(*a);
			// a.executeAform(*c);
		}
		catch(Aform::GradeTooLowException &e)
		{
			std::cerr << "\033[33m" << a->getname() << " was not able to execute the Aform " << c->get_name() << ": " << e.what() << "\033[0m" << std::endl;
		}
		std::cout << std::endl;

		// execute Aform from CEO
		try
		{
			c->execute(*b);
			// b.executeAform(*c);
		}
		catch(Aform::GradeTooLowException &e)
		{
			std::cerr << "\033[33m" << b->getname() << " was not able to execute the Aform " << c->get_name() << ": " << e.what() << "\033[0m" << std::endl;
		}
		std::cout << std::endl;

		std::cout << "\033[34mDeconstructing\033[0m" << std::endl;
		delete a;
		delete b;
		delete c;
		std::cout << std::endl;
	}
	std::cout << "--------------------------------------------------------------------------------------------------------------" << std::endl;
	{
		std::cout << std::endl;

		std::cout << "\033[34mConstructing\033[0m" << std::endl;
		Bureaucrat *a = new Bureaucrat("Emperor", 1);
		Intern *z = new Intern();
		Aform *b = z->makeForm("robotomy request", "Bender");
		Aform *c = z->makeForm("shrubbery creation", "Cristmas");
		// Aform *c = new ShrubberyCreationForm("christmas");
		std::cout << std::endl;

		std::cout << "\033[34mTesting\033[0m" << std::endl;
		std::cout << *a;
		std::cout << *b;
		std::cout << *c;
		std::cout << std::endl;

		b->beSigned(*a);
		a->signAform(*c);
		std::cout << std::endl;
		std::cout << *b;
		std::cout << *c;
		std::cout << std::endl;

		for (int i= 0; i < 10; i++)
			b->execute(*a);
		a->executeAform(*c);
		// c->execute(*a);
		std::cout << std::endl;

		std::cout << "\033[34mDeconstructing\033[0m" << std::endl;
		delete a;
		delete b;
		delete c;
		delete z;
		std::cout << std::endl;
	}
	return (0);
}