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
    std::stringstream ss;
    ss << "Default RobotomyRequestForm created: "
        << "name=\"" << getName() << "\""
        << ", signed=" << getSigned()
        << ", grade to sign=" << getGradeToSign()
        << ", grade to execute=" << getGradeToExecute()
        << ", target=\"" << _target << "\"";
    toolbox::logger::StepMark::info(ss.str());
}

RobotomyRequestForm::RobotomyRequestForm(const std::string& target)
    : AForm("Robotomy Request", 72, 45), _target(target) {
    std::stringstream ss;
    ss << "RobotomyRequestForm created: "
        << "name=\"" << getName() << "\""
        << ", signed=" << getSigned()
        << ", grade to sign=" << getGradeToSign()
        << ", grade to execute=" << getGradeToExecute()
        << ", target=\"" << _target << "\"";
    toolbox::logger::StepMark::info(ss.str());
}

RobotomyRequestForm::RobotomyRequestForm(const RobotomyRequestForm& src)
    : AForm(src), _target(src._target) {
    std::stringstream ss;
    ss << "RobotomyRequestForm copy created: "
        << "name=\"" << getName() << "\""
        << ", signed=" << getSigned()
        << ", grade to sign=" << getGradeToSign()
        << ", grade to execute=" << getGradeToExecute()
        << ", target=\"" << _target << "\"";
    toolbox::logger::StepMark::info(ss.str());
}

RobotomyRequestForm& RobotomyRequestForm::operator=
    (const RobotomyRequestForm& rhs) {
    std::stringstream ss;
    ss << "RobotomyRequestForm assignment operator called: "
        << "name=\"" << getName() << "\""
        << ", signed=" << getSigned()
        << ", grade to sign=" << getGradeToSign()
        << ", grade to execute=" << getGradeToExecute()
        << ", target=\"" << _target << "\"";
    toolbox::logger::StepMark::info(ss.str());
    if (this != &rhs) {
        AForm::operator=(rhs);
    }
    return *this;
}

RobotomyRequestForm::~RobotomyRequestForm() {
    std::stringstream ss;
    ss << "RobotomyRequestForm destroyed: "
        << "name=\"" << getName() << "\""
        << ", signed=" << getSigned()
        << ", grade to sign=" << getGradeToSign()
        << ", grade to execute=" << getGradeToExecute()
        << ", target=\"" << _target << "\"";
    toolbox::logger::StepMark::info(ss.str());
}

void RobotomyRequestForm::execute(const Bureaucrat& executor) const {
    std::stringstream ss;
    ss << "RobotomyRequestForm::execute called: name=\"" << getName()
        << "\", executor name=\"" << executor.getName()
        << "\", executor grade=" << executor.getGrade()
        << ", grade to execute=" << getGradeToExecute()
        << ", target=\"" << _target << "\"";
    toolbox::logger::StepMark::info(ss.str());
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
