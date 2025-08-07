#include <ex03/PresidentialPardonForm.hpp>

#include <iostream>
#include <sstream>
#include <string>

#include <toolbox/color.hpp>
#include <toolbox/StepMark.hpp>

PresidentialPardonForm::PresidentialPardonForm()
    : AForm("Presidential Pardon", 25, 5), _target("default") {
    std::stringstream logMsg;
    logMsg << "Default PresidentialPardonForm created: "
        << "name=\"" << getName() << "\""
        << ", signed=" << getSigned()
        << ", grade to sign=" << getGradeToSign()
        << ", grade to execute=" << getGradeToExecute()
        << ", target=\"" << _target << "\"";
    toolbox::logger::StepMark::info(logMsg.str());
}

PresidentialPardonForm::PresidentialPardonForm(const std::string& target)
    : AForm("Presidential Pardon", 25, 5), _target(target) {
    std::stringstream logMsg;
    logMsg << "PresidentialPardonForm created: "
        << "name=\"" << getName() << "\""
        << ", signed=" << getSigned()
        << ", grade to sign=" << getGradeToSign()
        << ", grade to execute=" << getGradeToExecute()
        << ", target=\"" << _target << "\"";
    toolbox::logger::StepMark::info(logMsg.str());
}

PresidentialPardonForm::PresidentialPardonForm
    (const PresidentialPardonForm& src) : AForm(src), _target(src._target) {
    std::stringstream logMsg;
    logMsg << "PresidentialPardonForm copy created: "
        << "name=\"" << getName() << "\""
        << ", signed=" << getSigned()
        << ", grade to sign=" << getGradeToSign()
        << ", grade to execute=" << getGradeToExecute()
        << ", target=\"" << _target << "\"";
    toolbox::logger::StepMark::info(logMsg.str());
}

PresidentialPardonForm& PresidentialPardonForm::operator=
    (const PresidentialPardonForm& rhs) {
    std::stringstream logMsg;
    logMsg << "PresidentialPardonForm assignment operator called: "
        << "name=\"" << getName() << "\""
        << ", signed=" << getSigned()
        << ", grade to sign=" << getGradeToSign()
        << ", grade to execute=" << getGradeToExecute()
        << ", target=\"" << _target << "\"";
    toolbox::logger::StepMark::info(logMsg.str());
    if (this != &rhs) {
        AForm::operator=(rhs);
    }
    return *this;
}

PresidentialPardonForm::~PresidentialPardonForm() {
    std::stringstream logMsg;
    logMsg << "PresidentialPardonForm destroyed: "
        << "name=\"" << getName() << "\""
        << ", signed=" << getSigned()
        << ", grade to sign=" << getGradeToSign()
        << ", grade to execute=" << getGradeToExecute()
        << ", target=\"" << _target << "\"";
    toolbox::logger::StepMark::info(logMsg.str());
}

void PresidentialPardonForm::execute(const Bureaucrat& executor) const {
    std::stringstream logMsg;
    logMsg << "PresidentialPardonForm::execute called: "
        << "name=\"" << getName() << "\""
        << ", executor name=\"" << executor.getName() << "\""
        << ", executor grade=" << executor.getGrade()
        << ", grade to execute=" << getGradeToExecute()
        << ", target=\"" << _target << "\"";
    toolbox::logger::StepMark::info(logMsg.str());
    AForm::execute(executor);
    std::cout << toolbox::color::green << _target
        << toolbox::color::reset << " has been pardoned by Zaphod Beeblebrox"
        << std::endl;
}
