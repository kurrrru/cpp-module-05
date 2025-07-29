#include <ex02/AForm.hpp>

#include <iostream>
#include <string>
#include <exception>

#include <ex02/Bureaucrat.hpp>
#include <toolbox/color.hpp>
#include <toolbox/stepmark.hpp>

AForm::AForm() : _name("default"), _signed(false), _gradeToSign(),
    _gradeToExecute() {
}

AForm::AForm(const std::string& name, int gradeToSign, int gradeToExecute) :
    _name(name), _signed(false), _gradeToSign(gradeToSign),
    _gradeToExecute(gradeToExecute) {
}

AForm::AForm(const AForm& src) : _name(src._name), _signed(src._signed),
    _gradeToSign(src._gradeToSign), _gradeToExecute(src._gradeToExecute) {
}

AForm& AForm::operator=(const AForm& rhs) {
    if (this != &rhs) {
        _signed = rhs._signed;
    }
    return *this;
}

AForm::~AForm() {
}

std::string AForm::getName() const {
    return _name;
}

bool AForm::getSigned() const {
    return _signed;
}

int AForm::getGradeToSign() const {
    return _gradeToSign.getGrade();
}

int AForm::getGradeToExecute() const {
    return _gradeToExecute.getGrade();
}

bool AForm::beSigned(const Bureaucrat& bureaucrat) {
    if (_signed) {
        return false;
    }
    if (bureaucrat.getGrade() > _gradeToSign.getGrade()) {
        throw GradeTooLowException();
    }
    _signed = true;
    return true;
}

const char* AForm::GradeTooHighException::what() const throw() {
    return "Grade is too high";
}

const char* AForm::GradeTooLowException::what() const throw() {
    return "Grade is too low";
}

const char* AForm::FormNotSignedException::what() const throw() {
    return "Form is not signed";
}

AForm::Grade::Grade() : _grade(_minGrade) {
}

AForm::Grade::Grade(int grade) {
    if (grade < _maxGrade) {
        throw GradeTooHighException();
    } else if (grade > _minGrade) {
        throw GradeTooLowException();
    }
    _grade = grade;
}

AForm::Grade::Grade(const Grade& src) : _grade(src._grade) {
}

AForm::Grade& AForm::Grade::operator=(const Grade& rhs) {
    if (this != &rhs) {
        _grade = rhs._grade;
    }
    return *this;
}

AForm::Grade::~Grade() {
}

int AForm::Grade::getGrade() const {
    return _grade;
}

void AForm::execute(const Bureaucrat& executor) const {
    if (_gradeToExecute.getGrade() < executor.getGrade()) {
        throw GradeTooLowException();
    }
    if (!_signed) {
        throw FormNotSignedException();
    }
}

std::ostream& operator<<(std::ostream& os, const AForm& form) {
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
