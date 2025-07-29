#include <iostream>
#include <string>
#include <sstream>

#include <ex02/AForm.hpp>
#include <toolbox/color.hpp>
#include <toolbox/stepmark.hpp>

AForm::GradeInvalidException::GradeInvalidException(
    const std::string& message) : _message(message) {
    std::stringstream ss;
    ss << "AForm::GradeInvalidException created: \"" << message << "\"";
    toolbox::logger::StepMark::notice(ss.str());
}

const char* AForm::GradeInvalidException::what() const throw() {
    std::stringstream ss;
    ss << "AForm::GradeInvalidException:what called: \""
        << _message << "\"";
    toolbox::logger::StepMark::debug(ss.str());
    return _message.c_str();
}

AForm::GradeInvalidException::~GradeInvalidException() throw() {
    std::stringstream ss;
    ss << "AForm::GradeInvalidException destroyed: \"" << _message << "\"";
    toolbox::logger::StepMark::debug(ss.str());
}

AForm::GradeTooHighException::GradeTooHighException(
    const std::string& message) : GradeInvalidException(message) {
    std::stringstream ss;
    ss << "AForm::GradeTooHighException created: \"" << message << "\"";
    toolbox::logger::StepMark::warning(ss.str());
}

AForm::GradeTooHighException::~GradeTooHighException() throw() {
    std::stringstream ss;
    ss << "AForm::GradeTooHighException destroyed";
    toolbox::logger::StepMark::info(ss.str());
}

AForm::GradeTooLowException::GradeTooLowException(
    const std::string& message) : GradeInvalidException(message) {
    std::stringstream ss;
    ss << "AForm::GradeTooLowException created: \"" << message << "\"";
    toolbox::logger::StepMark::warning(ss.str());
}

AForm::GradeTooLowException::~GradeTooLowException() throw() {
    std::stringstream ss;
    ss << "AForm::GradeTooLowException destroyed";
    toolbox::logger::StepMark::info(ss.str());
}

AForm::FormNotSignedException::FormNotSignedException(
    const std::string& message) : _message(message) {
    std::stringstream ss;
    ss << "AForm::FormNotSignedException created: \"" << message << "\"";
    toolbox::logger::StepMark::warning(ss.str());
}

const char* AForm::FormNotSignedException::what() const throw() {
    std::stringstream ss;
    ss << "AForm::FormNotSignedException:what called: \""
        << _message << "\"";
    toolbox::logger::StepMark::debug(ss.str());
    return _message.c_str();
}

AForm::FormNotSignedException::~FormNotSignedException() throw() {
    std::stringstream ss;
    ss << "AForm::FormNotSignedException destroyed: \"" << _message << "\"";
    toolbox::logger::StepMark::info(ss.str());
}
