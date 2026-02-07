#ifndef INTERN_HPP
#define INTERN_HPP

#include "PresidentialPardonForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "ShrubberyCreationForm.hpp"
#include "Aform.hpp"

class Intern
{
    public:
        Intern(void);
        Aform   *makeForm(std::string formName, std::string target);
        ~Intern();
};

typedef struct t_Form
{
    std::string name;
    Aform       *form;
}      Form;

#endif