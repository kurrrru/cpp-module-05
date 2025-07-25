#include <ex01/Form.hpp>

#include <iostream>
#include <string>
#include <sstream>
#include <exception>

#include <toolbox/color.hpp>
#include <toolbox/stepmark.hpp>

Form::Form() : _name("default"), _signed(false), _gradeToSign(),
    _gradeToExecute() {
    std::stringstream ss;
    ss << "Default Form created: "
        << "name=\"" << _name
        << "\", signed=" << _signed
        << ", grade to sign=" << _gradeToSign.getGrade()
        << ", grade to execute=" << _gradeToExecute.getGrade();
    toolbox::logger::StepMark::info(ss.str());
}

Form::Form(const std::string& name, int gradeToSign, int gradeToExecute) :
    _name(name), _signed(false), _gradeToSign(gradeToSign),
    _gradeToExecute(gradeToExecute) {
    std::stringstream ss;
    ss << "Form created: "
        << "name=\"" << _name
        << "\", signed=" << _signed
        << ", grade to sign=" << _gradeToSign.getGrade()
        << ", grade to execute=" << _gradeToExecute.getGrade();
    toolbox::logger::StepMark::info(ss.str());
}

Form::Form(const Form& src) : _name(src._name), _signed(src._signed),
    _gradeToSign(src._gradeToSign), _gradeToExecute(src._gradeToExecute) {
    std::stringstream ss;
    ss << "Form copy created: "
        << "name=\"" << _name
        << "\", signed=" << _signed
        << ", grade to sign=" << _gradeToSign.getGrade()
        << ", grade to execute=" << _gradeToExecute.getGrade();
    toolbox::logger::StepMark::info(ss.str());
}

// const member variables cannot be reassigned
Form& Form::operator=(const Form& rhs) {
    std::stringstream ss;
    ss << "Form assignment operator called: "
        << "name=\"" << rhs._name
        << "\", signed=" << rhs._signed
        << ", grade to sign=" << rhs._gradeToSign.getGrade()
        << ", grade to execute=" << rhs._gradeToExecute.getGrade();
    toolbox::logger::StepMark::info(ss.str());
    if (this != &rhs) {
        _signed = rhs._signed;
    }
    return *this;
}

Form::~Form() {
    std::stringstream ss;
    ss << "Form destroyed: "
        << "name=\"" << _name
        << "\", signed=" << _signed
        << ", grade to sign=" << _gradeToSign.getGrade()
        << ", grade to execute=" << _gradeToExecute.getGrade();
    toolbox::logger::StepMark::info(ss.str());
}

std::string Form::getName() const {
    std::stringstream ss;
    ss << "Form::getName called: name=\"" << _name << "\"";
    toolbox::logger::StepMark::debug(ss.str());
    return _name;
}

bool Form::getSigned() const {
    std::stringstream ss;
    ss << "Form::getSigned called: name=\"" << _name
        << "\", signed=" << _signed;
    toolbox::logger::StepMark::debug(ss.str());
    return _signed;
}

int Form::getGradeToSign() const {
    std::stringstream ss;
    ss << "Form::getGradeToSign called: name=\"" << _name
        << "\", grade to sign=" << _gradeToSign.getGrade();
    toolbox::logger::StepMark::debug(ss.str());
    return _gradeToSign.getGrade();
}

int Form::getGradeToExecute() const {
    std::stringstream ss;
    ss << "Form::getGradeToExecute called: name=\"" << _name
        << "\", grade to execute=" << _gradeToExecute.getGrade();
    toolbox::logger::StepMark::debug(ss.str());
    return _gradeToExecute.getGrade();
}

bool Form::beSigned(const Bureaucrat& bureaucrat) {
    std::stringstream ss;
    ss << "Form::beSigned called: name=\"" << _name
        << "\", bureaucrat name=\"" << bureaucrat.getName()
        << "\", bureaucrat grade=" << bureaucrat.getGrade()
        << ", grade to sign=" << _gradeToSign.getGrade()
        << ", old signed=" << _signed;
    toolbox::logger::StepMark::info(ss.str());
    if (_signed) {
        return false;
    }
    if (bureaucrat.getGrade() > _gradeToSign.getGrade()) {
        std::stringstream ss;
        ss << "Form::beSigned failed: "
            << "Bureaucrat \"" << bureaucrat.getName()
            << "\" (grade: " << bureaucrat.getGrade()
            << ") cannot sign form \"" << _name
            << "\" (grade to sign: " << _gradeToSign.getGrade() << ")";
        throw GradeTooLowException(ss.str());
    }
    _signed = true;
    return true;
}

std::ostream& operator<<(std::ostream& os, const Form& form) {
    os << toolbox::color::green << "Form: "
        << toolbox::color::reset << form.getName() << ", "
        << toolbox::color::green << "signed: "
        << toolbox::color::reset << form.getSigned() << ", "
        << toolbox::color::green << "grade to sign: "
        << toolbox::color::reset << form.getGradeToSign() << ", "
        << toolbox::color::green << "grade to execute: "
        << toolbox::color::reset << form.getGradeToExecute();
    return os;
}
