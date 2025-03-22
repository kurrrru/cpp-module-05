#include "Bureaucrat.hpp"

#include <iostream>
#include <string>

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

Bureaucrat::Bureaucrat() : _name("default"), _grade() {
}

Bureaucrat::Bureaucrat(const std::string& name, int grade) : _name(name),
    _grade(grade) {
}

Bureaucrat::Bureaucrat(const Bureaucrat& src) : _name(src._name),
    _grade(src._grade) {
}

// name is a const member variable, so it cannot be reassigned
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

void Bureaucrat::incrementGrade() {
    _grade.increment();
}

void Bureaucrat::decrementGrade() {
    _grade.decrement();
}

void Bureaucrat::signForm(Form& form) {
    try {
        if (form.beSigned(*this)) {
            std::cout << color::blue << getName() << color::reset << " signed "
                << color::green << form.getName() << color::reset << std::endl;
        } else {
            std::cout << color::blue << getName() << color::reset << " couldn't sign "
                << color::green << form.getName() << color::reset
                << " because it's already signed" << std::endl;
        }
    } catch (const std::exception& e) {
        std::cerr << color::blue << getName() << color::reset << " couldn't sign "
            << color::green << form.getName() << color::reset << " because "
            << color::red << e.what() << color::reset
            << std::endl;
    }
}

const char* Bureaucrat::GradeTooHighException::what() const throw() {
    return "Grade is too high";
}

const char* Bureaucrat::GradeTooLowException::what() const throw() {
    return "Grade is too low";
}

Bureaucrat::Grade::Grade() : _grade(_minGrade) {
}

Bureaucrat::Grade::Grade(int grade) {
    if (grade < _maxGrade) {
        throw GradeTooHighException();
    } else if (grade > _minGrade) {
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

int Bureaucrat::Grade::getGrade() const {
    return _grade;
}

void Bureaucrat::Grade::increment() {
    if (_grade == _maxGrade) {
        throw GradeTooHighException();
    }
    _grade--;
}

void Bureaucrat::Grade::decrement() {
    if (_grade == _minGrade) {
        throw GradeTooLowException();
    }
    _grade++;
}

std::ostream& operator<<(std::ostream& os, const Bureaucrat& bureaucrat) {
    os << color::cyan << bureaucrat.getName() << color::reset
        << ", bureaucrat grade " << color::blue << bureaucrat.getGrade()
        << color::reset;
    return os;
}
