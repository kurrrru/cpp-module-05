#include <ex01/Bureaucrat.hpp>

#include <iostream>
#include <string>
#include <sstream>

#include <toolbox/color.hpp>
#include <toolbox/stepmark.hpp>

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
    toolbox::logger::StepMark::debug(ss.str());
    return _name;
}

int Bureaucrat::getGrade() const {
    std::stringstream ss;
    ss << "Bureaucrat::getGrade called: name=\"" << _name
        << "\", grade=" << _grade.getGrade();
    toolbox::logger::StepMark::debug(ss.str());
    return _grade.getGrade();
}

void Bureaucrat::incrementGrade() {
    std::stringstream ss;
    ss << "Bureaucrat::incrementGrade called: name=\"" << _name
        << "\", old grade=" << _grade.getGrade()
        << ", new grade=" << _grade.getGrade() - 1;
    toolbox::logger::StepMark::info(ss.str());
    _grade.increment();
}

void Bureaucrat::decrementGrade() {
    std::stringstream ss;
    ss << "Bureaucrat::decrementGrade called: name=\"" << _name
        << "\", old grade=" << _grade.getGrade()
        << ", new grade=" << _grade.getGrade() + 1;
    toolbox::logger::StepMark::info(ss.str());
    _grade.decrement();
}

void Bureaucrat::signForm(Form& form) {
    std::stringstream ss;
    ss << "Bureaucrat::signForm called: name=\"" << _name
        << "\" (grade: " << _grade.getGrade() << "), "
        << "signing form: " << form.getName()
        << " (grade to sign: " << form.getGradeToSign() << ")";
    toolbox::logger::StepMark::info(ss.str());
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
        std::stringstream ss;
        ss << "Exception caught: " << e.what();
        toolbox::logger::StepMark::error(ss.str());
        std::cerr << toolbox::color::blue << getName()
            << toolbox::color::reset << " couldn't sign "
            << toolbox::color::green << form.getName()
            << toolbox::color::reset << " because "
            << toolbox::color::red << e.what()
            << toolbox::color::reset
            << std::endl;
    }
}

std::ostream& operator<<(std::ostream& os, const Bureaucrat& bureaucrat) {
    std::stringstream ss;
    ss << "operator<< for Bureaucrat: "
        << "name=\"" << bureaucrat.getName()
        << "\", grade=" << bureaucrat.getGrade();
    toolbox::logger::StepMark::debug(ss.str());

    os << toolbox::color::cyan << bureaucrat.getName()
        << toolbox::color::reset << ", bureaucrat grade "
        << toolbox::color::blue << bureaucrat.getGrade()
        << toolbox::color::reset;
    return os;
}
