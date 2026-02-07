#include "RobotomyRequestForm.hpp"
#include "Bureaucrat.hpp"
#include "Intern.hpp"
#include "Aform.hpp"

int main()
{
    Intern someRandomIntern;
    Aform* rrf;
    rrf = someRandomIntern.makeForm("aef creation", "Bender");
    if (rrf)
    {
        std::cout << rrf->get_name() << "\n";
        delete rrf;
    }
}