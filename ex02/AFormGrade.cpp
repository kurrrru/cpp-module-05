#include <iostream>
#include <string>
#include <sstream>

#include <ex02/AForm.hpp>
#include <toolbox/color.hpp>
#include <toolbox/stepmark.hpp>

AForm::Grade::Grade() : _grade(_minGrade) {
    std::stringstream ss;
    ss << "AForm::Grade default constructor called: grade=" << _grade;
    toolbox::logger::StepMark::trace(ss.str());
}

AForm::Grade::Grade(int grade) {
    std::stringstream ss;
    ss << "AForm::Grade constructor called: grade=" << grade;
    toolbox::logger::StepMark::trace(ss.str());
    if (grade < _maxGrade) {
        std::stringstream errMsg;
        errMsg << "AForm::Grade::Grade(int grade) failed: Grade is too high: "
            << "The grade must be between maxGrade=" << _maxGrade
            << " and minGrade=" << _minGrade << ". Provided grade=" << grade;
        throw GradeTooHighException(errMsg.str());
    } else if (grade > _minGrade) {
        std::stringstream errMsg;
        errMsg << "AForm::Grade::Grade(int grade) failed: Grade is too low: "
            << "The grade must be between maxGrade=" << _maxGrade
            << " and minGrade=" << _minGrade << ". Provided grade=" << grade;
        throw GradeTooLowException(errMsg.str());
    }
    _grade = grade;
}

AForm::Grade::Grade(const Grade& src) : _grade(src._grade) {
    std::stringstream ss;
    ss << "AForm::Grade copy constructor called: grade=" << _grade;
    toolbox::logger::StepMark::trace(ss.str());
}

AForm::Grade& AForm::Grade::operator=(const Grade& rhs) {
    std::stringstream ss;
    ss << "AForm::Grade assignment operator called: grade=" << rhs._grade;
    toolbox::logger::StepMark::trace(ss.str());
    if (this != &rhs) {
        _grade = rhs._grade;
    }
    return *this;
}

AForm::Grade::~Grade() {
    std::stringstream ss;
    ss << "AForm::Grade destructor called: grade=" << _grade;
    toolbox::logger::StepMark::trace(ss.str());
}

int AForm::Grade::getGrade() const {
    std::stringstream ss;
    ss << "AForm::Grade::getGrade called: grade=" << _grade;
    toolbox::logger::StepMark::trace(ss.str());
    return _grade;
}
