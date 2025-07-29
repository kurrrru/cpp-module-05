#include <ex02/RobotomyRequestForm.hpp>

#include <fstream>
#include <iostream>
#include <string>
#include <sstream>
#include <cstdlib>
#include <ctime>

#include <toolbox/color.hpp>
#include <toolbox/stepmark.hpp>

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
    AForm::execute(executor);
    std::cout << "Drilling noises" << std::endl;
    std::srand(std::time(NULL));
    bool success = std::rand() % 2;
    if (success) {
        std::cout << toolbox::color::green << _target
            << toolbox::color::reset << " robotomization succeeded"
            << std::endl;
    } else {
        std::cout << toolbox::color::green << _target
            << toolbox::color::reset << " robotomization failed"
            << std::endl;
    }
}
