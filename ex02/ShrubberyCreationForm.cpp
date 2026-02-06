#include "ShrubberyCreationForm.hpp"

void    ShrubberyCreationForm::execute(Bureaucrat const & executor) const
{
    if (!this->get_signed())
        throw Aform::FormNotSignedException();
    if (executor.getgrade() > this->get_grade_to_execute())
        throw Aform::GradeTooLowException();
    std::ofstream outfile;
    outfile.open((target + "_shrubbery").c_str());
    if (!outfile.is_open())
        throw std::runtime_error("Failed to create file");
    outfile << "      /\\      " << std::endl;
    outfile << "     /\\*\\     " << std::endl;
    outfile << "    /\\O\\*\\    " << std::endl;
    outfile << "   /*/\\/\\/\\   " << std::endl;
    outfile << "  /\\*\\/\\*\\/\\  " << std::endl;
    outfile << "      ||      " << std::endl;
    outfile.close();
}

ShrubberyCreationForm::~ShrubberyCreationForm()
{
    
}