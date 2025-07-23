#include <ex01/Bureaucrat.hpp>

#include <iostream>
#include <string>
#include <sstream>

#include <toolbox/color.hpp>
#include <toolbox/stepmark.hpp>

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
            std::cout << toolbox::color::blue << getName()
                << toolbox::color::reset << " signed "
                << toolbox::color::green << form.getName()
                << toolbox::color::reset << std::endl;
        } else {
            std::cout << toolbox::color::blue << getName()
                << toolbox::color::reset << " couldn't sign "
                << toolbox::color::green << form.getName()
                << toolbox::color::reset << " because it's already signed"
                << std::endl;
        }
    } catch (const std::exception& e) {
        std::cerr << toolbox::color::blue << getName()
            << toolbox::color::reset << " couldn't sign "
            << toolbox::color::green << form.getName()
            << toolbox::color::reset << " because "
            << toolbox::color::red << e.what()
            << toolbox::color::reset
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
    os << toolbox::color::cyan << bureaucrat.getName()
        << toolbox::color::reset << ", bureaucrat grade "
        << toolbox::color::blue << bureaucrat.getGrade()
        << toolbox::color::reset;
    return os;
}
