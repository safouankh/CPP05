#ifndef ROBOTOMY_REQUEST_FORM_HPP
#define ROBOTOMY_REQUEST_FORM_HPP

#include <cstdlib>
#include "Aform.hpp"
#include "Bureaucrat.hpp"

class RobotomyRequestForm : public Aform
{
    private:
    std::string target;
    public:
    RobotomyRequestForm(void) : Aform("Robotomy Request", 72, 45), target("target") {};
    RobotomyRequestForm(std::string _target) : Aform("Robotomy Request", 72, 45), target(_target) {};
    void		execute(Bureaucrat const & executor) const;
    virtual     ~RobotomyRequestForm();
};

#endif