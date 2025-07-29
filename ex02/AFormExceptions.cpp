#include <iostream>
#include <string>
#include <sstream>

#include <ex02/AForm.hpp>
#include <toolbox/color.hpp>
#include <toolbox/stepmark.hpp>

AForm::GradeInvalidException::GradeInvalidException(
    const std::string& message) : _message(message) {
    std::stringstream logMsg;
    logMsg << "AForm::GradeInvalidException created: \"" << message << "\"";
    toolbox::logger::StepMark::notice(logMsg.str());
}

const char* AForm::GradeInvalidException::what() const throw() {
    std::stringstream logMsg;
    logMsg << "AForm::GradeInvalidException:what called: \""
        << _message << "\"";
    toolbox::logger::StepMark::debug(logMsg.str());
    return _message.c_str();
}

AForm::GradeInvalidException::~GradeInvalidException() throw() {
    std::stringstream logMsg;
    logMsg << "AForm::GradeInvalidException destroyed: \"" << _message << "\"";
    toolbox::logger::StepMark::debug(logMsg.str());
}

AForm::GradeTooHighException::GradeTooHighException(
    const std::string& message) : GradeInvalidException(message) {
    std::stringstream logMsg;
    logMsg << "AForm::GradeTooHighException created: \"" << message << "\"";
    toolbox::logger::StepMark::warning(logMsg.str());
}

AForm::GradeTooHighException::~GradeTooHighException() throw() {
    std::stringstream logMsg;
    logMsg << "AForm::GradeTooHighException destroyed";
    toolbox::logger::StepMark::info(logMsg.str());
}

AForm::GradeTooLowException::GradeTooLowException(
    const std::string& message) : GradeInvalidException(message) {
    std::stringstream logMsg;
    logMsg << "AForm::GradeTooLowException created: \"" << message << "\"";
    toolbox::logger::StepMark::warning(logMsg.str());
}

AForm::GradeTooLowException::~GradeTooLowException() throw() {
    std::stringstream logMsg;
    logMsg << "AForm::GradeTooLowException destroyed";
    toolbox::logger::StepMark::info(logMsg.str());
}

AForm::FormNotSignedException::FormNotSignedException(
    const std::string& message) : _message(message) {
    std::stringstream logMsg;
    logMsg << "AForm::FormNotSignedException created: \"" << message << "\"";
    toolbox::logger::StepMark::warning(logMsg.str());
}

const char* AForm::FormNotSignedException::what() const throw() {
    std::stringstream logMsg;
    logMsg << "AForm::FormNotSignedException:what called: \""
        << _message << "\"";
    toolbox::logger::StepMark::debug(logMsg.str());
    return _message.c_str();
}

AForm::FormNotSignedException::~FormNotSignedException() throw() {
    std::stringstream logMsg;
    logMsg << "AForm::FormNotSignedException destroyed: \"" << _message << "\"";
    toolbox::logger::StepMark::info(logMsg.str());
}
