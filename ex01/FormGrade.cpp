#include <iostream>
#include <string>
#include <sstream>

#include <ex01/Form.hpp>
#include <toolbox/color.hpp>
#include <toolbox/stepmark.hpp>

Form::Grade::Grade() : _grade(_minGrade) {
    std::stringstream ss;
    ss << "Form::Grade default constructor called: grade=" << _grade;
    toolbox::logger::StepMark::trace(ss.str());
}

Form::Grade::Grade(int grade) {
    std::stringstream ss;
    ss << "Form::Grade constructor called: grade=" << grade;
    toolbox::logger::StepMark::trace(ss.str());
    if (grade < _maxGrade) {
        std::stringstream ss;
        ss << "Form::Grade::Grade(int grade) failed: Grade is too high: "
            << "The grade must be between maxGrade=" << _maxGrade
            << " and minGrade=" << _minGrade << ". Provided grade=" << grade;
        throw GradeTooHighException(ss.str());
    } else if (grade > _minGrade) {
        std::stringstream ss;
        ss << "Form::Grade::Grade(int grade) failed: Grade is too low: "
            << "The grade must be between maxGrade=" << _maxGrade
            << " and minGrade=" << _minGrade << ". Provided grade=" << grade;
        throw GradeTooLowException(ss.str());
    }
    _grade = grade;
}

Form::Grade::Grade(const Grade& src) : _grade(src._grade) {
    std::stringstream ss;
    ss << "Form::Grade copy constructor called: grade=" << _grade;
    toolbox::logger::StepMark::trace(ss.str());
}

Form::Grade& Form::Grade::operator=(const Grade& rhs) {
    std::stringstream ss;
    ss << "Form::Grade assignment operator called: grade=" << rhs._grade;
    toolbox::logger::StepMark::trace(ss.str());
    if (this != &rhs) {
        _grade = rhs._grade;
    }
    return *this;
}

Form::Grade::~Grade() {
    std::stringstream ss;
    ss << "Form::Grade destructor called: grade=" << _grade;
    toolbox::logger::StepMark::trace(ss.str());
}

int Form::Grade::getGrade() const {
    std::stringstream ss;
    ss << "Form::Grade::getGrade called: grade=" << _grade;
    toolbox::logger::StepMark::trace(ss.str());
    return _grade;
}
