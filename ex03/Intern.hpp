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
        Intern(const Intern& other);
        Intern& operator=(const Intern& other);
        Aform   *makeForm(std::string formName, std::string target);
        ~Intern();
};

typedef struct s_Form
{
    std::string name;
    Aform       *form;
}      t_Form;

#endif