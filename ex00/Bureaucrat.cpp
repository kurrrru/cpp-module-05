#include "Bureaucrat.hpp"

#include <iostream>
#include <string>

Bureaucrat::Bureaucrat() : _name("default"), _grade(150) {
}

Bureaucrat::Bureaucrat(const std::string& name, int grade) : _name(name), _grade(grade) {
}

Bureaucrat::Bureaucrat(const Bureaucrat& src) : _name(src._name), _grade(src._grade) {
}

Bureaucrat& Bureaucrat::operator=(const Bureaucrat& rhs) {
    if (this != &rhs) {
        _grade = rhs._grade;
    }
    return *this;
}

Bureaucrat::~Bureaucrat() {
}

std::string Bureaucrat::getName() const {
    return _name;
}

int Bureaucrat::getGrade() const {
    return _grade.getGrade();
}

int Bureaucrat::Grade::getGrade() const {
    return _grade;
}

const char* Bureaucrat::GradeTooHighException::what() const throw() {
    return "Grade is too high";
}

const char* Bureaucrat::GradeTooLowException::what() const throw() {
    return "Grade is too low";
}

Bureaucrat::Grade::Grade() : _grade(150) {
}

Bureaucrat::Grade::Grade(int grade) {
    if (grade < 1) {
        throw GradeTooHighException();
    } else if (grade > 150) {
        throw GradeTooLowException();
    }
    _grade = grade;
}

Bureaucrat::Grade::Grade(const Grade& src) : _grade(src._grade) {
}

Bureaucrat::Grade& Bureaucrat::Grade::operator=(const Grade& rhs) {
    if (this != &rhs) {
        _grade = rhs._grade;
    }
    return *this;
}

Bureaucrat::Grade::~Grade() {
}

std::ostream& operator<<(std::ostream& os, const Bureaucrat& bureaucrat) {
    os << bureaucrat.getName() << ", bureaucrat grade " << bureaucrat.getGrade();
    return os;
}
