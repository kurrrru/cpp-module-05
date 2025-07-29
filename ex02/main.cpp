#include <string>
#include <sstream>
#include <iostream>

#include <ex02/Bureaucrat.hpp>
#include <ex02/AForm.hpp>
#include <ex02/PresidentialPardonForm.hpp>
#include <ex02/RobotomyRequestForm.hpp>
#include <ex02/ShrubberyCreationForm.hpp>
#include <toolbox/color.hpp>
#include <toolbox/stepmark.hpp>

int main() {
    toolbox::logger::StepMark::setLogFile("bureaucrat.log");
    toolbox::logger::StepMark::setLevel(toolbox::logger::INFO);
    for (int i = -29; i <= 180; i += 30) {
        std::cout << "i = " << i << std::endl;
        std::cout << "PresidentialPardonForm" << std::endl;
        try {
            Bureaucrat bureaucrat("bureaucrat", i);
            PresidentialPardonForm form("target");

            bureaucrat.signForm(form);
            bureaucrat.executeForm(form);
        } catch (const std::exception& e) {
            std::stringstream logMsg;
            logMsg << "Exception caught: " << e.what();
            toolbox::logger::StepMark::error(logMsg.str());
            std::cerr << toolbox::color::red << "Error: " << e.what()
                    << toolbox::color::reset
                    << std::endl;
        }

        std::cout << "RobotomyRequestForm" << std::endl;
        try {
            Bureaucrat bureaucrat("bureaucrat", i);
            RobotomyRequestForm form("target");

            bureaucrat.signForm(form);
            bureaucrat.executeForm(form);
        } catch (const std::exception& e) {
            std::stringstream logMsg;
            logMsg << "Exception caught: " << e.what();
            toolbox::logger::StepMark::error(logMsg.str());
            std::cerr << toolbox::color::red << "Error: " << e.what()
                    << toolbox::color::reset
                    << std::endl;
        }

        std::cout << "ShrubberyCreationForm" << std::endl;
        try {
            Bureaucrat bureaucrat("bureaucrat", i);
            ShrubberyCreationForm form("target");

            bureaucrat.signForm(form);
            bureaucrat.executeForm(form);
        } catch (const std::exception& e) {
            std::stringstream logMsg;
            logMsg << "Exception caught: " << e.what();
            toolbox::logger::StepMark::error(logMsg.str());
            std::cerr << toolbox::color::red << "Error: " << e.what()
                    << toolbox::color::reset
                    << std::endl;
        }
    }
}
