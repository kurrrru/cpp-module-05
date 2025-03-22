#include <iostream>
#include <string>
#include <exception>

#include "Bureaucrat.hpp"

int main(void) {
    for (int i = -30; i <= 180; i += 30)
    {
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
            std::cerr << e.what() << std::endl;
        }
    }
}
