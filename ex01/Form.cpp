#include <ex01/Form.hpp>

#include <iostream>
#include <string>
#include <sstream>
#include <exception>

#include <toolbox/color.hpp>
#include <toolbox/StepMark.hpp>

Form::Form() : _name("default"), _signed(false), _gradeToSign(),
    _gradeToExecute() {
    std::stringstream logMsg;
    logMsg << "Default Form created: "
        << "name=\"" << _name
        << "\", signed=" << _signed
        << ", grade to sign=" << _gradeToSign.getGrade()
        << ", grade to execute=" << _gradeToExecute.getGrade();
    toolbox::logger::StepMark::info(logMsg.str());
}

Form::Form(const std::string& name, int gradeToSign, int gradeToExecute) :
    _name(name), _signed(false), _gradeToSign(gradeToSign),
    _gradeToExecute(gradeToExecute) {
    std::stringstream logMsg;
    logMsg << "Form created: "
        << "name=\"" << _name
        << "\", signed=" << _signed
        << ", grade to sign=" << _gradeToSign.getGrade()
        << ", grade to execute=" << _gradeToExecute.getGrade();
    toolbox::logger::StepMark::info(logMsg.str());
}

Form::Form(const Form& src) : _name(src._name), _signed(src._signed),
    _gradeToSign(src._gradeToSign), _gradeToExecute(src._gradeToExecute) {
    std::stringstream logMsg;
    logMsg << "Form copy created: "
        << "name=\"" << _name
        << "\", signed=" << _signed
        << ", grade to sign=" << _gradeToSign.getGrade()
        << ", grade to execute=" << _gradeToExecute.getGrade();
    toolbox::logger::StepMark::info(logMsg.str());
}

// const member variables cannot be reassigned
Form& Form::operator=(const Form& rhs) {
    std::stringstream logMsg;
    logMsg << "Form assignment operator called: "
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

Form::~Form() {
    std::stringstream logMsg;
    logMsg << "Form destroyed: "
        << "name=\"" << _name
        << "\", signed=" << _signed
        << ", grade to sign=" << _gradeToSign.getGrade()
        << ", grade to execute=" << _gradeToExecute.getGrade();
    toolbox::logger::StepMark::info(logMsg.str());
}

std::string Form::getName() const {
    std::stringstream logMsg;
    logMsg << "Form::getName called: name=\"" << _name << "\"";
    toolbox::logger::StepMark::debug(logMsg.str());
    return _name;
}

bool Form::getSigned() const {
    std::stringstream logMsg;
    logMsg << "Form::getSigned called: name=\"" << _name
        << "\", signed=" << _signed;
    toolbox::logger::StepMark::debug(logMsg.str());
    return _signed;
}

int Form::getGradeToSign() const {
    std::stringstream logMsg;
    logMsg << "Form::getGradeToSign called: name=\"" << _name
        << "\", grade to sign=" << _gradeToSign.getGrade();
    toolbox::logger::StepMark::debug(logMsg.str());
    return _gradeToSign.getGrade();
}

int Form::getGradeToExecute() const {
    std::stringstream logMsg;
    logMsg << "Form::getGradeToExecute called: name=\"" << _name
        << "\", grade to execute=" << _gradeToExecute.getGrade();
    toolbox::logger::StepMark::debug(logMsg.str());
    return _gradeToExecute.getGrade();
}

bool Form::beSigned(const Bureaucrat& bureaucrat) {
    std::stringstream logMsg;
    logMsg << "Form::beSigned called: name=\"" << _name
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
        errMsg << "Form::beSigned failed: "
            << "Bureaucrat \"" << bureaucrat.getName()
            << "\" (grade: " << bureaucrat.getGrade()
            << ") cannot sign form \"" << _name
            << "\" (grade to sign: " << _gradeToSign.getGrade() << ")";
        throw GradeTooLowException(errMsg.str());
    }
    _signed = true;
    return true;
}

std::ostream& operator<<(std::ostream& os, const Form& form) {
    os << "Form: "
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
