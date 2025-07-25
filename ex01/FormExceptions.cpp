#include <iostream>
#include <string>
#include <sstream>

#include <ex01/Form.hpp>
#include <toolbox/color.hpp>
#include <toolbox/stepmark.hpp>

Form::GradeInvalidException::GradeInvalidException(
    const std::string& message) : _message(message) {
    std::stringstream ss;
    ss << "Form::GradeInvalidException created: \"" << message << "\"";
    toolbox::logger::StepMark::notice(ss.str());
}

const char* Form::GradeInvalidException::what() const throw() {
    std::stringstream ss;
    ss << "Form::GradeInvalidException:what called: \""
        << _message << "\"";
    toolbox::logger::StepMark::debug(ss.str());
    return _message.c_str();
}

Form::GradeInvalidException::~GradeInvalidException() throw() {
    std::stringstream ss;
    ss << "Form::GradeInvalidException destroyed: \"" << _message << "\"";
    toolbox::logger::StepMark::debug(ss.str());
}

Form::GradeTooHighException::GradeTooHighException(
    const std::string& message) : GradeInvalidException(message) {
    std::stringstream ss;
    ss << "Form::GradeTooHighException created: \"" << message << "\"";
    toolbox::logger::StepMark::warning(ss.str());
}

Form::GradeTooHighException::~GradeTooHighException() throw() {
    std::stringstream ss;
    ss << "Form::GradeTooHighException destroyed";
    toolbox::logger::StepMark::info(ss.str());
}

Form::GradeTooLowException::GradeTooLowException(
    const std::string& message) : GradeInvalidException(message) {
    std::stringstream ss;
    ss << "Form::GradeTooLowException created: \"" << message << "\"";
    toolbox::logger::StepMark::warning(ss.str());
}

Form::GradeTooLowException::~GradeTooLowException() throw() {
    std::stringstream ss;
    ss << "Form::GradeTooLowException destroyed";
    toolbox::logger::StepMark::info(ss.str());
}
