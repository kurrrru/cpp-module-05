#include <iostream>
#include <string>
#include <exception>

#include "Bureaucrat.hpp"

int main(void) {
    try {
        Bureaucrat bureaucrat("bureaucrat", 150);
        std::cout << bureaucrat << std::endl;
        std::cout << "Grade: " << bureaucrat.getGrade() << std::endl;
        std::cout << "Name: " << bureaucrat.getName() << std::endl;
    } catch (const std::exception& e) {
        std::cerr << e.what() << std::endl;
    }
}
