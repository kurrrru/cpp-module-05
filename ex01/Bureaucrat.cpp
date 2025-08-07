#include <ex01/Bureaucrat.hpp>

#include <iostream>
#include <string>
#include <sstream>

#include <toolbox/color.hpp>
#include <toolbox/StepMark.hpp>

Bureaucrat::Bureaucrat() : _name("default"), _grade() {
    std::stringstream logMsg;
    logMsg << "Default Bureaucrat created: "
        << "name=\"" << _name
        << "\", grade=" << _grade.getGrade();
    toolbox::logger::StepMark::info(logMsg.str());
}

Bureaucrat::Bureaucrat(const std::string& name, int grade) : _name(name),
    _grade(grade) {
    std::stringstream logMsg;
    logMsg << "Bureaucrat created: "
        << "name=\"" << _name
        << "\", grade=" << _grade.getGrade();
    toolbox::logger::StepMark::info(logMsg.str());
}

Bureaucrat::Bureaucrat(const Bureaucrat& src) : _name(src._name),
    _grade(src._grade) {
    std::stringstream logMsg;
    logMsg << "Bureaucrat copy created: "
        << "name=\"" << _name
        << "\", grade=" << _grade.getGrade();
    toolbox::logger::StepMark::info(logMsg.str());
}

// name is a const member variable, so it cannot be reassigned
Bureaucrat& Bureaucrat::operator=(const Bureaucrat& rhs) {
    std::stringstream logMsg;
    logMsg << "Bureaucrat assignment operator called: "
        << "name=\"" << rhs._name
        << "\", grade=" << rhs._grade.getGrade();
    toolbox::logger::StepMark::info(logMsg.str());
    if (this != &rhs) {
        _grade = rhs._grade;
    }
    return *this;
}

Bureaucrat::~Bureaucrat() {
    std::stringstream logMsg;
    logMsg << "Bureaucrat destroyed: "
        << "name=\"" << _name
        << "\", grade=" << _grade.getGrade();
    toolbox::logger::StepMark::info(logMsg.str());
}

std::string Bureaucrat::getName() const {
    std::stringstream logMsg;
    logMsg << "Bureaucrat::getName called: name=\"" << _name << "\"";
    toolbox::logger::StepMark::debug(logMsg.str());
    return _name;
}

int Bureaucrat::getGrade() const {
    std::stringstream logMsg;
    logMsg << "Bureaucrat::getGrade called: name=\"" << _name
        << "\", grade=" << _grade.getGrade();
    toolbox::logger::StepMark::debug(logMsg.str());
    return _grade.getGrade();
}

void Bureaucrat::incrementGrade() {
    std::stringstream logMsg;
    logMsg << "Bureaucrat::incrementGrade called: name=\"" << _name
        << "\", old grade=" << _grade.getGrade()
        << ", new grade=" << _grade.getGrade() - 1;
    toolbox::logger::StepMark::info(logMsg.str());
    _grade.increment();
}

void Bureaucrat::decrementGrade() {
    std::stringstream logMsg;
    logMsg << "Bureaucrat::decrementGrade called: name=\"" << _name
        << "\", old grade=" << _grade.getGrade()
        << ", new grade=" << _grade.getGrade() + 1;
    toolbox::logger::StepMark::info(logMsg.str());
    _grade.decrement();
}

void Bureaucrat::signForm(Form& form) {
    std::stringstream logMsg;
    logMsg << "Bureaucrat::signForm called: name=\"" << _name
        << "\" (grade: " << _grade.getGrade() << "), "
        << "signing form: " << form.getName()
        << " (grade to sign: " << form.getGradeToSign() << ")";
    toolbox::logger::StepMark::notice(logMsg.str());
    try {
        if (form.beSigned(*this)) {
            std::cout << toolbox::color::blue << getName()
                << toolbox::color::reset << " signed "
                << toolbox::color::green << form.getName()
                << toolbox::color::reset
                << std::endl;
        } else {
            std::cout << toolbox::color::blue << getName()
                << toolbox::color::reset << " couldn't sign "
                << toolbox::color::green << form.getName()
                << toolbox::color::reset << " because it's already signed"
                << std::endl;
        }
    } catch (const std::exception& e) {
        std::stringstream logMsg;
        logMsg << "Exception caught: " << e.what();
        toolbox::logger::StepMark::error(logMsg.str());
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
    std::stringstream logMsg;
    logMsg << "operator<< for Bureaucrat: "
        << "name=\"" << bureaucrat.getName()
        << "\", grade=" << bureaucrat.getGrade();
    toolbox::logger::StepMark::debug(logMsg.str());

    os << toolbox::color::cyan << bureaucrat.getName()
        << toolbox::color::reset << ", bureaucrat grade "
        << toolbox::color::blue << bureaucrat.getGrade()
        << toolbox::color::reset;
    return os;
}
