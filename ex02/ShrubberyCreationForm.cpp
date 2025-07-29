#include <ex02/ShrubberyCreationForm.hpp>

#include <fstream>
#include <iostream>
#include <string>
#include <sstream>
#include <cstdlib>
#include <ctime>

#include <toolbox/color.hpp>
#include <toolbox/stepmark.hpp>

ShrubberyCreationForm::ShrubberyCreationForm()
    : AForm("Shrubbery Creation", 145, 137), _target("default") {
    std::stringstream ss;
    ss << "Default ShrubberyCreationForm created: "
        << "name=\"" << getName() << "\""
        << ", signed=" << getSigned()
        << ", grade to sign=" << getGradeToSign()
        << ", grade to execute=" << getGradeToExecute()
        << ", target=\"" << _target << "\"";
    toolbox::logger::StepMark::info(ss.str());
}

ShrubberyCreationForm::ShrubberyCreationForm(const std::string& target)
    : AForm("Shrubbery Creation", 145, 137), _target(target) {
    std::stringstream ss;
    ss << "ShrubberyCreationForm created: "
        << "name=\"" << getName() << "\""
        << ", signed=" << getSigned()
        << ", grade to sign=" << getGradeToSign()
        << ", grade to execute=" << getGradeToExecute()
        << ", target=\"" << _target << "\"";
    toolbox::logger::StepMark::info(ss.str());
}

ShrubberyCreationForm::ShrubberyCreationForm(const ShrubberyCreationForm& src)
    : AForm(src), _target(src._target) {
    std::stringstream ss;
    ss << "ShrubberyCreationForm copy created: "
        << "name=\"" << getName() << "\""
        << ", signed=" << getSigned()
        << ", grade to sign=" << getGradeToSign()
        << ", grade to execute=" << getGradeToExecute()
        << ", target=\"" << _target << "\"";
    toolbox::logger::StepMark::info(ss.str());
}

ShrubberyCreationForm& ShrubberyCreationForm::operator=
    (const ShrubberyCreationForm& rhs) {
    std::stringstream ss;
    ss << "ShrubberyCreationForm assignment operator called: "
        << "name=\"" << getName() << "\""
        << ", signed=" << getSigned()
        << ", grade to sign=" << getGradeToSign()
        << ", grade to execute=" << getGradeToExecute()
        << ", target=\"" << _target << "\"";
    toolbox::logger::StepMark::info(ss.str());
    if (this != &rhs) {
        AForm::operator=(rhs);
    }
    return *this;
}

ShrubberyCreationForm::~ShrubberyCreationForm() {
    std::stringstream ss;
    ss << "ShrubberyCreationForm destroyed: "
        << "name=\"" << getName() << "\""
        << ", signed=" << getSigned()
        << ", grade to sign=" << getGradeToSign()
        << ", grade to execute=" << getGradeToExecute()
        << ", target=\"" << _target << "\"";
    toolbox::logger::StepMark::info(ss.str());
}

void ShrubberyCreationForm::execute(const Bureaucrat& executor) const {
    std::stringstream ss;
    ss << "ShrubberyCreationForm::execute called: name=\"" << getName()
        << "\", executor name=\"" << executor.getName()
        << "\", executor grade=" << executor.getGrade()
        << ", grade to execute=" << getGradeToExecute()
        << ", target=\"" << _target << "\"";
    toolbox::logger::StepMark::info(ss.str());

    AForm::execute(executor);
    std::string filename = _target + "_shrubbery";
    std::ofstream file(filename.c_str());
    if (!file.is_open()) {
        std::stringstream errorMsg;
        errorMsg << "Failed to create file: " << filename;
        throw FileCreationException(errorMsg.str());
    }

    std::srand(std::time(NULL));
    const int maxTreeSize = 10;
    const int treeSize = std::rand() % (maxTreeSize - 2) + 3;
    for (int i = 0; i < treeSize; i++) {
        for (int j = 0; j < treeSize - i - 1; j++) {
            file << " ";
        }
        for (int j = 0; j < i * 2 + 1; j++) {
            file << "/";
        }
        file << "\\" << std::endl;
    }
    for (int i = 0; i < 2; i++) {
        for (int j = 0; j < treeSize - 1; j++) {
            file << " ";
        }
        file << "||" << std::endl;
    }

    file.close();
}

ShrubberyCreationForm::FileCreationException::FileCreationException(
    const std::string& message)
    : _message(message) {
    std::stringstream ss;
    ss << "ShrubberyCreationForm::FileCreationException: " << _message;
    toolbox::logger::StepMark::warning(ss.str());
}

const char* ShrubberyCreationForm::FileCreationException::what() const throw() {
    std::stringstream ss;
    ss << "ShrubberyCreationForm::FileCreationException: " << _message;
    toolbox::logger::StepMark::debug(ss.str());
    return _message.c_str();
}

ShrubberyCreationForm::FileCreationException::~FileCreationException() throw() {
    std::stringstream ss;
    ss << "ShrubberyCreationForm::FileCreationException destroyed: "
        << _message;
    toolbox::logger::StepMark::info(ss.str());
}
