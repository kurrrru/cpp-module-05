#include <iostream>
#include <string>
#include <sstream>

#include <ex02/Bureaucrat.hpp>
#include <toolbox/color.hpp>
#include <toolbox/stepmark.hpp>

Bureaucrat::GradeInvalidException::GradeInvalidException(
    const std::string& message) : _message(message) {
    std::stringstream logMsg;
    logMsg << "Bureaucrat::GradeInvalidException created: \"" << message << "\"";
    toolbox::logger::StepMark::notice(logMsg.str());
}

const char* Bureaucrat::GradeInvalidException::what() const throw() {
    std::stringstream logMsg;
    logMsg << "Bureaucrat::GradeInvalidException:what called: \""
        << _message << "\"";
    toolbox::logger::StepMark::debug(logMsg.str());
    return _message.c_str();
}

Bureaucrat::GradeInvalidException::~GradeInvalidException() throw() {
    std::stringstream logMsg;
    logMsg << "Bureaucrat::GradeInvalidException destroyed: \"" << _message << "\"";
    toolbox::logger::StepMark::debug(logMsg.str());
}

Bureaucrat::GradeTooHighException::GradeTooHighException(
    const std::string& message) : GradeInvalidException(message) {
    std::stringstream logMsg;
    logMsg << "Bureaucrat::GradeTooHighException created: \"" << message << "\"";
    toolbox::logger::StepMark::warning(logMsg.str());
}

Bureaucrat::GradeTooHighException::~GradeTooHighException()
    throw() {
    std::stringstream logMsg;
    logMsg << "Bureaucrat::GradeTooHighException destroyed";
    toolbox::logger::StepMark::info(logMsg.str());
}

Bureaucrat::GradeTooLowException::GradeTooLowException(
    const std::string& message) : GradeInvalidException(message) {
    std::stringstream logMsg;
    logMsg << "Bureaucrat::GradeTooLowException created: \"" << message << "\"";
    toolbox::logger::StepMark::warning(logMsg.str());
}

Bureaucrat::GradeTooLowException::~GradeTooLowException() throw() {
    std::stringstream logMsg;
    logMsg << "Bureaucrat::GradeTooLowException destroyed";
    toolbox::logger::StepMark::info(logMsg.str());
}
