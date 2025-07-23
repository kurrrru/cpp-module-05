#include <iostream>
#include <string>
#include <sstream>

#include "ex00/Bureaucrat.hpp"
#include "toolbox/color.hpp"
#include "toolbox/stepmark.hpp"

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
        std::stringstream ss;
        ss << "Bureaucrat::Grade::Grade(int grade) failed: Grade is too high: "
            << "The grade must be between maxGrade=" << _maxGrade
            << " and minGrade=" << _minGrade << ". Provided grade=" << grade;
        throw GradeTooHighException(ss.str());
    } else if (grade > _minGrade) {
        std::stringstream ss;
        ss << "Bureaucrat::Grade::Grade(int grade) failed: Grade is too low: "
            << "The grade must be between maxGrade=" << _maxGrade
            << " and minGrade=" << _minGrade << ". Provided grade=" << grade;
        throw GradeTooLowException(ss.str());
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
        std::stringstream ss;
        ss << "Bureaucrat::Grade::increment() failed: Grade is too high: "
            << "The grade must be between maxGrade=" << _maxGrade
            << " and minGrade=" << _minGrade << ". Current grade=" << _grade
            << " and incremented grade=" << _grade - 1;
        throw GradeTooHighException(ss.str());
    }
    _grade--;
}

void Bureaucrat::Grade::decrement() {
    std::stringstream ss;
    ss << "Bureaucrat::Grade::decrement called: grade=" << _grade;
    toolbox::logger::StepMark::debug(ss.str());
    if (_grade == _minGrade) {
        std::stringstream ss;
        ss << "Bureaucrat::Grade::decrement() failed: Grade is too low: "
            << "The grade must be between maxGrade=" << _maxGrade
            << " and minGrade=" << _minGrade << ". Current grade=" << _grade
            << " and decremented grade=" << _grade + 1;
        throw GradeTooLowException(ss.str());
    }
    _grade++;
}
