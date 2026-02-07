#include "PresidentialPardonForm.hpp"

void		PresidentialPardonForm::execute(Bureaucrat const & executor) const
{
    if (!this->get_signed())
        throw Aform::FormNotSignedException();
    if (executor.getgrade() > this->get_grade_to_execute())
        throw Aform::GradeTooLowException();
    std::cout << target << " has been pardoned by Zaphod Beeblebrox\n";
}

PresidentialPardonForm::~PresidentialPardonForm()
{

}