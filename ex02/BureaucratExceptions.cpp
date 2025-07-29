#include <iostream>
#include <string>
#include <sstream>

#include <ex02/Bureaucrat.hpp>
#include <toolbox/color.hpp>
#include <toolbox/stepmark.hpp>

Bureaucrat::GradeInvalidException::GradeInvalidException(
    const std::string& message) : _message(message) {
    std::stringstream ss;
    ss << "Bureaucrat::GradeInvalidException created: \"" << message << "\"";
    toolbox::logger::StepMark::notice(ss.str());
}

const char* Bureaucrat::GradeInvalidException::what() const throw() {
    std::stringstream ss;
    ss << "Bureaucrat::GradeInvalidException:what called: \""
        << _message << "\"";
    toolbox::logger::StepMark::debug(ss.str());
    return _message.c_str();
}

Bureaucrat::GradeInvalidException::~GradeInvalidException() throw() {
    std::stringstream ss;
    ss << "Bureaucrat::GradeInvalidException destroyed: \"" << _message << "\"";
    toolbox::logger::StepMark::debug(ss.str());
}

Bureaucrat::GradeTooHighException::GradeTooHighException(
    const std::string& message) : GradeInvalidException(message) {
    std::stringstream ss;
    ss << "Bureaucrat::GradeTooHighException created: \"" << message << "\"";
    toolbox::logger::StepMark::warning(ss.str());
}

Bureaucrat::GradeTooHighException::~GradeTooHighException()
    throw() {
    std::stringstream ss;
    ss << "Bureaucrat::GradeTooHighException destroyed";
    toolbox::logger::StepMark::info(ss.str());
}

Bureaucrat::GradeTooLowException::GradeTooLowException(
    const std::string& message) : GradeInvalidException(message) {
    std::stringstream ss;
    ss << "Bureaucrat::GradeTooLowException created: \"" << message << "\"";
    toolbox::logger::StepMark::warning(ss.str());
}

Bureaucrat::GradeTooLowException::~GradeTooLowException() throw() {
    std::stringstream ss;
    ss << "Bureaucrat::GradeTooLowException destroyed";
    toolbox::logger::StepMark::info(ss.str());
}
