#ifndef SHRUBBERY_CREATION_FORM_HPP
#define SHRUBBERY_CREATION_FORM_HPP

#include <fstream>
#include "Aform.hpp"
#include "Bureaucrat.hpp"

class ShrubberyCreationForm : public Aform
{
    private:
        std::string target;
    public:
        ShrubberyCreationForm(void) : Aform("Shrubbery Creation", 145, 137) ,target("target") {};
        ShrubberyCreationForm(std::string _target) : Aform("Shrubbery Creation", 145, 137) ,target(_target) {};
		ShrubberyCreationForm(const ShrubberyCreationForm& other);
		ShrubberyCreationForm& operator=(const ShrubberyCreationForm& other);
		void		execute(Bureaucrat const & executor) const;
        virtual     ~ShrubberyCreationForm();
};

#endif