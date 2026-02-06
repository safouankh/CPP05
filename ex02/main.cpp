#include "RobotomyRequestForm.hpp"
#include "Bureaucrat.hpp"

int main()
{
    srand(time(NULL));
    Bureaucrat *b = new Bureaucrat("Agent", 20);
    RobotomyRequestForm *form = new RobotomyRequestForm("Marvin");
    try
    {
        form->beSigned(*b);
    }
    catch(const std::exception& e)
    {
        std::cerr << e.what() << '\n';
    }

    b->executeAform(*form);
    b->executeAform(*form);
    b->executeAform(*form);
    b->executeAform(*form);
    delete b;
    delete form;
}