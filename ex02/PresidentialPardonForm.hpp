#ifndef PRESIDENTIAL_PARDON_FORM_HPP
#define PRESIDENTIAL_PARDON_FORM_HPP

#include "Aform.hpp"
#include "Bureaucrat.hpp"

class PresidentialPardonForm : public Aform
{
    private:
    std::string target;
    public:
    PresidentialPardonForm(void) : Aform("Presidential Pardon", 25, 5), target("target") {};
    PresidentialPardonForm(std::string _target) : Aform("Presidential Pardon", 25, 5), target(_target) {};
    PresidentialPardonForm(const PresidentialPardonForm& other);
    PresidentialPardonForm& operator=(const PresidentialPardonForm& other);
    void		execute(Bureaucrat const & executor) const;
    virtual     ~PresidentialPardonForm();
};

#endif