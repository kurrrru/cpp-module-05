#include <iostream>
#include <string>
#include <sstream>

#include <ex01/Form.hpp>
#include <toolbox/color.hpp>
#include <toolbox/stepmark.hpp>

Form::Grade::Grade() : _grade(_minGrade) {
    std::stringstream logMsg;
    logMsg << "Form::Grade default constructor called: grade=" << _grade;
    toolbox::logger::StepMark::trace(logMsg.str());
}

Form::Grade::Grade(int grade) {
    std::stringstream logMsg;
    logMsg << "Form::Grade constructor called: grade=" << grade;
    toolbox::logger::StepMark::trace(logMsg.str());
    if (grade < _maxGrade) {
        std::stringstream errMsg;
        errMsg << "Form::Grade::Grade(int grade) failed: Grade is too high: "
            << "The grade must be between maxGrade=" << _maxGrade
            << " and minGrade=" << _minGrade << ". Provided grade=" << grade;
        throw GradeTooHighException(errMsg.str());
    } else if (grade > _minGrade) {
        std::stringstream errMsg;
        errMsg << "Form::Grade::Grade(int grade) failed: Grade is too low: "
            << "The grade must be between maxGrade=" << _maxGrade
            << " and minGrade=" << _minGrade << ". Provided grade=" << grade;
        throw GradeTooLowException(errMsg.str());
    }
    _grade = grade;
}

Form::Grade::Grade(const Grade& src) : _grade(src._grade) {
    std::stringstream logMsg;
    logMsg << "Form::Grade copy constructor called: grade=" << _grade;
    toolbox::logger::StepMark::trace(logMsg.str());
}

Form::Grade& Form::Grade::operator=(const Grade& rhs) {
    std::stringstream logMsg;
    logMsg << "Form::Grade assignment operator called: grade=" << rhs._grade;
    toolbox::logger::StepMark::trace(logMsg.str());
    if (this != &rhs) {
        _grade = rhs._grade;
    }
    return *this;
}

Form::Grade::~Grade() {
    std::stringstream logMsg;
    logMsg << "Form::Grade destructor called: grade=" << _grade;
    toolbox::logger::StepMark::trace(logMsg.str());
}

int Form::Grade::getGrade() const {
    std::stringstream logMsg;
    logMsg << "Form::Grade::getGrade called: grade=" << _grade;
    toolbox::logger::StepMark::trace(logMsg.str());
    return _grade;
}
