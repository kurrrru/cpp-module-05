#include "AForm.hpp"

#include <iostream>
#include <string>
#include <exception>

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
    os << color::green << "Form: " << color::reset << form.getName() << ", "
        << color::green << "signed: " << color::reset << form.getSigned()
        << ", " << color::green << "grade to sign: " << color::reset
        << form.getGradeToSign() << ", " << color::green
        << "grade to execute: " << color::reset << form.getGradeToExecute();
    return os;
}
