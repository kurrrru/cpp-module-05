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
