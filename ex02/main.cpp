#include <string>
#include <iostream>

#include "Bureaucrat.hpp"
#include "AForm.hpp"
#include "PresidentialPardonForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "ShrubberyCreationForm.hpp"

int main() {
    std::cout << "PresidentialPardonForm" << std::endl;
    {
        Bureaucrat bureaucrat("bureaucrat", 1);
        PresidentialPardonForm form("target");

        bureaucrat.signForm(form);
        bureaucrat.executeForm(form);
    }

    std::cout << "RobotomyRequestForm" << std::endl;
    {
        Bureaucrat bureaucrat("bureaucrat", 1);
        RobotomyRequestForm form("target");

        bureaucrat.signForm(form);
        bureaucrat.executeForm(form);
    }

    std::cout << "ShrubberyCreationForm" << std::endl;
    {
        Bureaucrat bureaucrat("bureaucrat", 1);
        ShrubberyCreationForm form("target");

        bureaucrat.signForm(form);
        bureaucrat.executeForm(form);
    }
}
