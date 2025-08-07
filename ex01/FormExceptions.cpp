#include <iostream>
#include <string>
#include <sstream>

#include <ex01/Form.hpp>
#include <toolbox/color.hpp>
#include <toolbox/StepMark.hpp>

Form::GradeInvalidException::GradeInvalidException(
    const std::string& message) : _message(message) {
    std::stringstream logMsg;
    logMsg << "Form::GradeInvalidException created: \"" << message << "\"";
    toolbox::logger::StepMark::notice(logMsg.str());
}

const char* Form::GradeInvalidException::what() const throw() {
    std::stringstream logMsg;
    logMsg << "Form::GradeInvalidException:what called: \""
        << _message << "\"";
    toolbox::logger::StepMark::debug(logMsg.str());
    return _message.c_str();
}

Form::GradeInvalidException::~GradeInvalidException() throw() {
    std::stringstream logMsg;
    logMsg << "Form::GradeInvalidException destroyed: \"" << _message << "\"";
    toolbox::logger::StepMark::debug(logMsg.str());
}

Form::GradeTooHighException::GradeTooHighException(
    const std::string& message) : GradeInvalidException(message) {
    std::stringstream logMsg;
    logMsg << "Form::GradeTooHighException created: \"" << message << "\"";
    toolbox::logger::StepMark::warning(logMsg.str());
}

Form::GradeTooHighException::~GradeTooHighException() throw() {
    std::stringstream logMsg;
    logMsg << "Form::GradeTooHighException destroyed";
    toolbox::logger::StepMark::info(logMsg.str());
}

Form::GradeTooLowException::GradeTooLowException(
    const std::string& message) : GradeInvalidException(message) {
    std::stringstream logMsg;
    logMsg << "Form::GradeTooLowException created: \"" << message << "\"";
    toolbox::logger::StepMark::warning(logMsg.str());
}

Form::GradeTooLowException::~GradeTooLowException() throw() {
    std::stringstream logMsg;
    logMsg << "Form::GradeTooLowException destroyed";
    toolbox::logger::StepMark::info(logMsg.str());
}
