#include "RobotomyRequestForm.hpp"

void		RobotomyRequestForm::execute(Bureaucrat const & executor) const
{
    if (!this->get_signed())
        throw Aform::FormNotSignedException();
    if (executor.getgrade() > this->get_grade_to_execute())
        throw Aform::GradeTooLowException();
    std::cout << "* drilling noises *" << std::endl;
    if (rand() % 2 == 0)
        std::cout << target << " SUCCESS!" << std::endl;
    else
        std::cout << target << " FAILED!" << std::endl;
}

RobotomyRequestForm::~RobotomyRequestForm()
{

}