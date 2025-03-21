#include "Form.hpp"

#include <iostream>
#include <string>
#include <exception>

Form::Form() : _name("default"), _signed(false), _gradeToSign(),
    _gradeToExecute() {
}

Form::Form(const std::string& name, int gradeToSign, int gradeToExecute) :
    _name(name), _signed(false), _gradeToSign(gradeToSign),
    _gradeToExecute(gradeToExecute) {
}

Form::Form(const Form& src) : _name(src._name), _signed(src._signed),
    _gradeToSign(src._gradeToSign), _gradeToExecute(src._gradeToExecute) {
}

Form& Form::operator=(const Form& rhs) {
    if (this != &rhs) {
        _signed = rhs._signed;
    }
    return *this;
}

Form::~Form() {
}

std::string Form::getName() const {
    return _name;
}

bool Form::getSigned() const {
    return _signed;
}

int Form::getGradeToSign() const {
    return _gradeToSign.getGrade();
}

int Form::getGradeToExecute() const {
    return _gradeToExecute.getGrade();
}

void Form::beSigned(const Bureaucrat& bureaucrat) {
    if (bureaucrat.getGrade() > _gradeToSign.getGrade()) {
        throw GradeTooLowException();
    }
    _signed = true;
}

const char* Form::GradeTooHighException::what() const throw() {
    return "Grade is too high";
}

const char* Form::GradeTooLowException::what() const throw() {
    return "Grade is too low";
}

Form::Grade::Grade() : _grade(_minGrade) {
}

Form::Grade::Grade(int grade) {
    if (grade < _maxGrade) {
        throw GradeTooHighException();
    } else if (grade > _minGrade) {
        throw GradeTooLowException();
    }
    _grade = grade;
}

Form::Grade::Grade(const Grade& src) : _grade(src._grade) {
}

Form::Grade& Form::Grade::operator=(const Grade& rhs) {
    if (this != &rhs) {
        _grade = rhs._grade;
    }
    return *this;
}

int Form::Grade::getGrade() const {
    return _grade;
}

std::ostream& operator<<(std::ostream& os, const Form& form) {
    os << "Form: " << form.getName() << ", signed: " << form.getSigned()
        << ", grade to sign: " << form.getGradeToSign()
        << ", grade to execute: " << form.getGradeToExecute();
    return os;
}
