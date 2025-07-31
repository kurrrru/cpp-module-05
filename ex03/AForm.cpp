#include <ex03/AForm.hpp>

#include <iostream>
#include <string>
#include <sstream>
#include <exception>

#include <ex03/Bureaucrat.hpp>
#include <toolbox/color.hpp>
#include <toolbox/stepmark.hpp>

AForm::AForm() : _name("default"), _signed(false), _gradeToSign(),
    _gradeToExecute() {
    std::stringstream logMsg;
    logMsg << "Default AForm created: "
        << "name=\"" << _name
        << "\", signed=" << _signed
        << ", grade to sign=" << _gradeToSign.getGrade()
        << ", grade to execute=" << _gradeToExecute.getGrade();
    toolbox::logger::StepMark::info(logMsg.str());
}

AForm::AForm(const std::string& name, int gradeToSign, int gradeToExecute) :
    _name(name), _signed(false), _gradeToSign(gradeToSign),
    _gradeToExecute(gradeToExecute) {
    std::stringstream logMsg;
    logMsg << "AForm created: "
        << "name=\"" << _name
        << "\", signed=" << _signed
        << ", grade to sign=" << _gradeToSign.getGrade()
        << ", grade to execute=" << _gradeToExecute.getGrade();
    toolbox::logger::StepMark::info(logMsg.str());
}

AForm::AForm(const AForm& src) : _name(src._name), _signed(src._signed),
    _gradeToSign(src._gradeToSign), _gradeToExecute(src._gradeToExecute) {
    std::stringstream logMsg;
    logMsg << "AForm copy created: "
        << "name=\"" << _name
        << "\", signed=" << _signed
        << ", grade to sign=" << _gradeToSign.getGrade()
        << ", grade to execute=" << _gradeToExecute.getGrade();
    toolbox::logger::StepMark::info(logMsg.str());
}

// const member variables cannot be reassigned
AForm& AForm::operator=(const AForm& rhs) {
    std::stringstream logMsg;
    logMsg << "AForm assignment operator called: "
        << "name=\"" << rhs._name
        << "\", signed=" << rhs._signed
        << ", grade to sign=" << rhs._gradeToSign.getGrade()
        << ", grade to execute=" << rhs._gradeToExecute.getGrade();
    toolbox::logger::StepMark::info(logMsg.str());
    if (this != &rhs) {
        _signed = rhs._signed;
    }
    return *this;
}

AForm::~AForm() {
    std::stringstream logMsg;
    logMsg << "AForm destroyed: "
        << "name=\"" << _name
        << "\", signed=" << _signed
        << ", grade to sign=" << _gradeToSign.getGrade()
        << ", grade to execute=" << _gradeToExecute.getGrade();
    toolbox::logger::StepMark::info(logMsg.str());
}

std::string AForm::getName() const {
    std::stringstream logMsg;
    logMsg << "AForm::getName called: name=\"" << _name << "\"";
    toolbox::logger::StepMark::debug(logMsg.str());
    return _name;
}

bool AForm::getSigned() const {
    std::stringstream logMsg;
    logMsg << "AForm::getSigned called: name=\"" << _name
        << "\", signed=" << _signed;
    toolbox::logger::StepMark::debug(logMsg.str());
    return _signed;
}

int AForm::getGradeToSign() const {
    std::stringstream logMsg;
    logMsg << "AForm::getGradeToSign called: name=\"" << _name
        << "\", grade to sign=" << _gradeToSign.getGrade();
    toolbox::logger::StepMark::debug(logMsg.str());
    return _gradeToSign.getGrade();
}

int AForm::getGradeToExecute() const {
    std::stringstream logMsg;
    logMsg << "AForm::getGradeToExecute called: name=\"" << _name
        << "\", grade to execute=" << _gradeToExecute.getGrade();
    toolbox::logger::StepMark::debug(logMsg.str());
    return _gradeToExecute.getGrade();
}

bool AForm::beSigned(const Bureaucrat& bureaucrat) {
    std::stringstream logMsg;
    logMsg << "AForm::beSigned called: name=\"" << _name
        << "\", bureaucrat name=\"" << bureaucrat.getName()
        << "\", bureaucrat grade=" << bureaucrat.getGrade()
        << ", grade to sign=" << _gradeToSign.getGrade()
        << ", old signed=" << _signed;
    toolbox::logger::StepMark::info(logMsg.str());
    if (_signed) {
        return false;
    }
    if (bureaucrat.getGrade() > _gradeToSign.getGrade()) {
        std::stringstream errMsg;
        errMsg << "AForm::beSigned failed: "
            << "Bureaucrat \"" << bureaucrat.getName()
            << "\" (grade: " << bureaucrat.getGrade()
            << ") cannot sign form \"" << _name
            << "\" (grade to sign: " << _gradeToSign.getGrade() << ")";
        throw GradeTooLowException(errMsg.str());
    }
    _signed = true;
    return true;
}

void AForm::execute(const Bureaucrat& executor) const {
    std::stringstream logMsg;
    logMsg << "AForm::execute called: name=\"" << _name
        << "\", executor name=\"" << executor.getName()
        << "\", executor grade=" << executor.getGrade()
        << ", grade to execute=" << _gradeToExecute.getGrade();
    toolbox::logger::StepMark::info(logMsg.str());
    if (_gradeToExecute.getGrade() < executor.getGrade()) {
        std::stringstream errMsg;
        errMsg << "AForm::execute failed: "
                << "Bureaucrat \"" << executor.getName()
                << "\" (grade: " << executor.getGrade()
                << ") cannot execute form \"" << _name
                << "\" (grade to execute: " << _gradeToExecute.getGrade()
                << ")";
        throw GradeTooLowException(errMsg.str());
    }
    if (!_signed) {
        std::stringstream errMsg;
        errMsg << "AForm::execute failed: "
            << "Form \"" << _name
            << "\" is not signed, cannot execute";
        throw FormNotSignedException(errMsg.str());
    }
}

std::ostream& operator<<(std::ostream& os, const AForm& form) {
    os << "AForm: "
        << toolbox::color::green << form.getName()
        << toolbox::color::reset << ", signed: "
        << toolbox::color::yellow << form.getSigned()
        << toolbox::color::reset << ", grade to sign: "
        << toolbox::color::magenta << form.getGradeToSign()
        << toolbox::color::reset << ", grade to execute: "
        << toolbox::color::magenta << form.getGradeToExecute()
        << toolbox::color::reset;
    return os;
}
