#include "ex00/Bureaucrat.hpp"

#include <iostream>
#include <string>
#include <sstream>

#include "toolbox/color.hpp"
#include "toolbox/stepmark.hpp"

Bureaucrat::Bureaucrat() : _name("default"), _grade() {
    std::stringstream ss;
    ss << "Default Bureaucrat created: "
        << "name=\"" << _name
        << "\", grade=" << _grade.getGrade();
    toolbox::logger::StepMark::info(ss.str());
}

Bureaucrat::Bureaucrat(const std::string& name, int grade) : _name(name),
    _grade(grade) {
    std::stringstream ss;
    ss << "Bureaucrat created: "
        << "name=\"" << _name
        << "\", grade=" << _grade.getGrade();
    toolbox::logger::StepMark::info(ss.str());
}

Bureaucrat::Bureaucrat(const Bureaucrat& src) : _name(src._name),
    _grade(src._grade) {
    std::stringstream ss;
    ss << "Bureaucrat copy created: "
        << "name=\"" << _name
        << "\", grade=" << _grade.getGrade();
    toolbox::logger::StepMark::info(ss.str());
}

// name is a const member variable, so it cannot be reassigned
Bureaucrat& Bureaucrat::operator=(const Bureaucrat& rhs) {
    std::stringstream ss;
    ss << "Bureaucrat assignment operator called: "
        << "name=\"" << rhs._name
        << "\", grade=" << rhs._grade.getGrade();
    toolbox::logger::StepMark::info(ss.str());
    if (this != &rhs) {
        _grade = rhs._grade;
    }
    return *this;
}

Bureaucrat::~Bureaucrat() {
    std::stringstream ss;
    ss << "Bureaucrat destroyed: "
        << "name=\"" << _name
        << "\", grade=" << _grade.getGrade();
    toolbox::logger::StepMark::info(ss.str());
}

std::string Bureaucrat::getName() const {
    std::stringstream ss;
    ss << "Bureaucrat::getName called: name=\"" << _name << "\"";
    toolbox::logger::StepMark::info(ss.str());
    return _name;
}

int Bureaucrat::getGrade() const {
    std::stringstream ss;
    ss << "Bureaucrat::getGrade called: name=\"" << _name
        << "\", grade=" << _grade.getGrade();
    toolbox::logger::StepMark::info(ss.str());
    return _grade.getGrade();
}

void Bureaucrat::incrementGrade() {
    std::stringstream ss;
    ss << "Bureaucrat::incrementGrade called: name=\"" << _name
        << "\", previous grade=" << _grade.getGrade();
    toolbox::logger::StepMark::info(ss.str());
    _grade.increment();
}

void Bureaucrat::decrementGrade() {
    std::stringstream ss;
    ss << "Bureaucrat::decrementGrade called: name=\"" << _name
        << "\", previous grade=" << _grade.getGrade();
    toolbox::logger::StepMark::info(ss.str());
    _grade.decrement();
}

Bureaucrat::GradeInvalidException::GradeInvalidException(
    const std::string& message) : _message(message) {
    std::stringstream ss;
    ss << "Bureaucrat::GradeInvalidException created: \"" << message << "\"";
    toolbox::logger::StepMark::notice(ss.str());
}

const char* Bureaucrat::GradeInvalidException::what() const throw() {
    std::stringstream ss;
    ss << "Bureaucrat::GradeInvalidException:what called: \""
        << _message << "\"";
    toolbox::logger::StepMark::debug(ss.str());
    return _message.c_str();
}

Bureaucrat::GradeInvalidException::~GradeInvalidException() throw() {
    std::stringstream ss;
    ss << "Bureaucrat::GradeInvalidException destroyed: \"" << _message << "\"";
    toolbox::logger::StepMark::debug(ss.str());
}

Bureaucrat::GradeTooHighException::GradeTooHighException(
    const std::string& message) : GradeInvalidException(message) {
    std::stringstream ss;
    ss << "Bureaucrat::GradeTooHighException created: \"" << message << "\"";
    toolbox::logger::StepMark::warning(ss.str());
}

Bureaucrat::GradeTooHighException::~GradeTooHighException()
    throw() {
    std::stringstream ss;
    ss << "Bureaucrat::GradeTooHighException destroyed";
    toolbox::logger::StepMark::info(ss.str());
}

Bureaucrat::GradeTooLowException::GradeTooLowException(
    const std::string& message) : GradeInvalidException(message) {
    std::stringstream ss;
    ss << "Bureaucrat::GradeTooLowException created: \"" << message << "\"";
    toolbox::logger::StepMark::warning(ss.str());
}

Bureaucrat::GradeTooLowException::~GradeTooLowException() throw() {
    std::stringstream ss;
    ss << "Bureaucrat::GradeTooLowException destroyed";
    toolbox::logger::StepMark::info(ss.str());
}

Bureaucrat::Grade::Grade() : _grade(_minGrade) {
    std::stringstream ss;
    ss << "Bureaucrat::Grade default constructor called: grade=" << _grade;
    toolbox::logger::StepMark::trace(ss.str());
}

Bureaucrat::Grade::Grade(int grade) {
    std::stringstream ss;
    ss << "Bureaucrat::Grade constructor called: grade=" << grade;
    toolbox::logger::StepMark::trace(ss.str());
    if (grade < _maxGrade) {
        throw GradeTooHighException();
    } else if (grade > _minGrade) {
        throw GradeTooLowException();
    }
    _grade = grade;
}

Bureaucrat::Grade::Grade(const Grade& src) : _grade(src._grade) {
    std::stringstream ss;
    ss << "Bureaucrat::Grade copy constructor called: grade=" << _grade;
    toolbox::logger::StepMark::trace(ss.str());
}

Bureaucrat::Grade& Bureaucrat::Grade::operator=(const Grade& rhs) {
    std::stringstream ss;
    ss << "Bureaucrat::Grade assignment operator called: grade=" << rhs._grade;
    toolbox::logger::StepMark::trace(ss.str());
    if (this != &rhs) {
        _grade = rhs._grade;
    }
    return *this;
}

Bureaucrat::Grade::~Grade() {
    std::stringstream ss;
    ss << "Bureaucrat::Grade destructor called: grade=" << _grade;
    toolbox::logger::StepMark::trace(ss.str());
}

int Bureaucrat::Grade::getGrade() const {
    std::stringstream ss;
    ss << "Bureaucrat::Grade::getGrade called: grade=" << _grade;
    toolbox::logger::StepMark::trace(ss.str());
    return _grade;
}

void Bureaucrat::Grade::increment() {
    std::stringstream ss;
    ss << "Bureaucrat::Grade::increment called: grade=" << _grade;
    toolbox::logger::StepMark::debug(ss.str());
    if (_grade == _maxGrade) {
        throw GradeTooHighException();
    }
    _grade--;
}

void Bureaucrat::Grade::decrement() {
    std::stringstream ss;
    ss << "Bureaucrat::Grade::decrement called: grade=" << _grade;
    toolbox::logger::StepMark::debug(ss.str());
    if (_grade == _minGrade) {
        throw GradeTooLowException();
    }
    _grade++;
}

std::ostream& operator<<(std::ostream& os, const Bureaucrat& bureaucrat) {
    std::stringstream ss;
    ss << "operator<< for Bureaucrat: "
        << "name=\"" << bureaucrat.getName()
        << "\", grade=" << bureaucrat.getGrade();
    toolbox::logger::StepMark::debug(ss.str());

    os << toolbox::color::cyan << bureaucrat.getName() << toolbox::color::reset
        << ", bureaucrat grade " << toolbox::color::blue
        << bureaucrat.getGrade()
        << toolbox::color::reset;
    return os;
}
