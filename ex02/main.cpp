#include <string>
#include <iostream>

#include "Bureaucrat.hpp"
#include "AForm.hpp"
#include "PresidentialPardonForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "ShrubberyCreationForm.hpp"

int main() {
    for (int i = -29; i <= 180; i += 30) {
        std::cout << "PresidentialPardonForm" << std::endl;
        try {
            Bureaucrat bureaucrat("bureaucrat", i);
            PresidentialPardonForm form("target");

            bureaucrat.signForm(form);
            bureaucrat.executeForm(form);
        } catch (const std::exception& e) {
            std::cerr << e.what() << std::endl;
        }

        std::cout << "RobotomyRequestForm" << std::endl;
        try {
            Bureaucrat bureaucrat("bureaucrat", i);
            RobotomyRequestForm form("target");

            bureaucrat.signForm(form);
            bureaucrat.executeForm(form);
        } catch (const std::exception& e) {
            std::cerr << e.what() << std::endl;
        }

        std::cout << "ShrubberyCreationForm" << std::endl;
        try {
            Bureaucrat bureaucrat("bureaucrat", i);
            ShrubberyCreationForm form("target");

            bureaucrat.signForm(form);
            bureaucrat.executeForm(form);
        } catch (const std::exception& e) {
            std::cerr << e.what() << std::endl;
        }
    }
}
