#include "Intern.hpp"

Intern::Intern(void)
{

}

void clear_memory(Form forms[], int avoid)
{
    for (int i = 0; i < 3; i++)
    {
        if (i != avoid)
            delete forms[i].form;
    }
}

Aform   *Intern::makeForm(std::string formName, std::string target)
{
    Form forms[3] = 
    {
        {"shrubbery creation", new ShrubberyCreationForm(target)},
        {"robotomy request", new RobotomyRequestForm(target)},
        {"presidential pardon", new PresidentialPardonForm(target)}
    };
    for (int i = 0; i < 3; i++)
    {
        if (forms[i].name == formName)
        {
            clear_memory(forms, i);
            std::cout << "intern create " << forms[i].form->get_name() << '\n';
            return forms[i].form;
        }
    }
    std::cout << "no form exist\n";
    clear_memory(forms, 4);
    return NULL;
}

Intern::~Intern()
{

}
