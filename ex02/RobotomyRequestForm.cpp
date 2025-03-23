#include "RobotomyRequestForm.hpp"

#include <fstream>
#include <iostream>
#include <string>
#include <cstdlib>
#include <ctime>

namespace {
namespace color {
const char red[] = "\033[1;31m";
const char green[] = "\033[1;32m";
const char yellow[] = "\033[1;33m";
const char blue[] = "\033[1;34m";
const char magenta[] = "\033[1;35m";
const char cyan[] = "\033[1;36m";
const char reset[] = "\033[0m";
}
}  // namespace

RobotomyRequestForm::RobotomyRequestForm()
    : AForm("Robotomy Request", 72, 45), _target("default") {
}

RobotomyRequestForm::RobotomyRequestForm(const std::string& target)
    : AForm("Robotomy Request", 72, 45), _target(target) {
}

RobotomyRequestForm::RobotomyRequestForm(const RobotomyRequestForm& src)
    : AForm(src), _target(src._target) {
}

RobotomyRequestForm& RobotomyRequestForm::operator=
    (const RobotomyRequestForm& rhs) {
    if (this != &rhs) {
        AForm::operator=(rhs);
    }
    return *this;
}

RobotomyRequestForm::~RobotomyRequestForm() {
}

void RobotomyRequestForm::execute(const Bureaucrat& executor) const {
    if (getGradeToExecute() < executor.getGrade()) {
        throw GradeTooLowException();
    }
    std::cout << "Drilling noises" << std::endl;
    std::srand(std::time(NULL));
    bool success = std::rand() % 2;
    if (success) {
        std::cout << color::green
            << _target << color::reset << " robotomization succeeded"
            << std::endl;
    } else {
        std::cout << color::green
            << _target << color::reset << " robotomization failed"
            << std::endl;
        throw RobotomizeException();
    }
}

const char* RobotomyRequestForm::RobotomizeException::what() const throw() {
    return "Robotomization failed";
}
