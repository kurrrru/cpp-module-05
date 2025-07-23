#include <iostream>
#include <string>
#include <sstream>
#include <exception>

#include "ex00/Bureaucrat.hpp"
#include "toolbox/stepmark.hpp"
#include "toolbox/color.hpp"

int main(void) {
    toolbox::logger::StepMark::setLogFile("bureaucrat.log");
    toolbox::logger::StepMark::setLevel(toolbox::logger::INFO);
    for (int i = -30; i <= 180; i += 30) {
        std::cout << "i = " << i << std::endl;
        try {
            Bureaucrat bureaucrat("bureaucrat", i);
            std::cout << bureaucrat << std::endl;
            std::cout << "Grade: " << bureaucrat.getGrade() << std::endl;
            std::cout << "Name: " << bureaucrat.getName() << std::endl;
            bureaucrat.incrementGrade();
            std::cout << "Grade: " << bureaucrat.getGrade() << std::endl;
            bureaucrat.decrementGrade();
            bureaucrat.decrementGrade();
            std::cout << "Grade: " << bureaucrat.getGrade() << std::endl;
        } catch (const std::exception& e) {
            std::stringstream ss;
            ss << "Exception caught: " << e.what();
            toolbox::logger::StepMark::error(ss.str());
            std::cerr << toolbox::color::red << "Error: " << e.what()
                    << toolbox::color::reset << std::endl;
        }
        int j = i + 1;
        std::cout << "j = " << j << std::endl;
        try {
            Bureaucrat bureaucrat("bureaucrat", j);
            std::cout << bureaucrat << std::endl;
            std::cout << "Grade: " << bureaucrat.getGrade() << std::endl;
            std::cout << "Name: " << bureaucrat.getName() << std::endl;
            bureaucrat.incrementGrade();
            std::cout << "Grade: " << bureaucrat.getGrade() << std::endl;
            bureaucrat.decrementGrade();
            bureaucrat.decrementGrade();
            std::cout << "Grade: " << bureaucrat.getGrade() << std::endl;
        } catch (const std::exception& e) {
            std::stringstream ss;
            ss << "Exception caught: " << e.what();
            toolbox::logger::StepMark::error(ss.str());
            std::cerr << toolbox::color::red << "Error: " << e.what()
                    << toolbox::color::reset << std::endl;
        }
    }
}
