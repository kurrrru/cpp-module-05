#include <iostream>
#include <string>
#include <sstream>

#include <ex03/Bureaucrat.hpp>
#include <toolbox/color.hpp>
#include <toolbox/stepmark.hpp>

Bureaucrat::Grade::Grade() : _grade(_minGrade) {
    std::stringstream logMsg;
    logMsg << "Bureaucrat::Grade default constructor called: grade=" << _grade;
    toolbox::logger::StepMark::trace(logMsg.str());
}

Bureaucrat::Grade::Grade(int grade) {
    std::stringstream logMsg;
    logMsg << "Bureaucrat::Grade constructor called: grade=" << grade;
    toolbox::logger::StepMark::trace(logMsg.str());
    if (grade < _maxGrade) {
        std::stringstream errMsg;
        errMsg
            << "Bureaucrat::Grade::Grade(int grade) failed: Grade is too high: "
            << "The grade must be between maxGrade=" << _maxGrade
            << " and minGrade=" << _minGrade << ". Provided grade=" << grade;
        throw GradeTooHighException(errMsg.str());
    } else if (grade > _minGrade) {
        std::stringstream errMsg;
        errMsg
            << "Bureaucrat::Grade::Grade(int grade) failed: Grade is too low: "
            << "The grade must be between maxGrade=" << _maxGrade
            << " and minGrade=" << _minGrade << ". Provided grade=" << grade;
        throw GradeTooLowException(errMsg.str());
    }
    _grade = grade;
}

Bureaucrat::Grade::Grade(const Grade& src) : _grade(src._grade) {
    std::stringstream logMsg;
    logMsg << "Bureaucrat::Grade copy constructor called: grade=" << _grade;
    toolbox::logger::StepMark::trace(logMsg.str());
}

Bureaucrat::Grade& Bureaucrat::Grade::operator=(const Grade& rhs) {
    std::stringstream logMsg;
    logMsg << "Bureaucrat::Grade assignment operator called: grade="
        << rhs._grade;
    toolbox::logger::StepMark::trace(logMsg.str());
    if (this != &rhs) {
        _grade = rhs._grade;
    }
    return *this;
}

Bureaucrat::Grade::~Grade() {
    std::stringstream logMsg;
    logMsg << "Bureaucrat::Grade destructor called: grade=" << _grade;
    toolbox::logger::StepMark::trace(logMsg.str());
}

int Bureaucrat::Grade::getGrade() const {
    std::stringstream logMsg;
    logMsg << "Bureaucrat::Grade::getGrade called: grade=" << _grade;
    toolbox::logger::StepMark::trace(logMsg.str());
    return _grade;
}

void Bureaucrat::Grade::increment() {
    std::stringstream logMsg;
    logMsg << "Bureaucrat::Grade::increment called: old grade="
        << _grade << ", new grade=" << _grade - 1;
    toolbox::logger::StepMark::debug(logMsg.str());
    if (_grade == _maxGrade) {
        std::stringstream errMsg;
        errMsg << "Bureaucrat::Grade::increment() failed: Grade is too high: "
            << "The grade must be between maxGrade=" << _maxGrade
            << " and minGrade=" << _minGrade << ". Old grade=" << _grade
            << " and new grade=" << _grade - 1;
        throw GradeTooHighException(errMsg.str());
    }
    _grade--;
}

void Bureaucrat::Grade::decrement() {
    std::stringstream logMsg;
    logMsg << "Bureaucrat::Grade::decrement called: old grade="
        << _grade << ", new grade=" << _grade + 1;
    toolbox::logger::StepMark::debug(logMsg.str());
    if (_grade == _minGrade) {
        std::stringstream errMsg;
        errMsg << "Bureaucrat::Grade::decrement() failed: Grade is too low: "
            << "The grade must be between maxGrade=" << _maxGrade
            << " and minGrade=" << _minGrade << ". Old grade=" << _grade
            << " and new grade=" << _grade + 1;
        throw GradeTooLowException(errMsg.str());
    }
    _grade++;
}
