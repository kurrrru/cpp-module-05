#include <ex03/Intern.hpp>

#include <string>
#include <sstream>
#include <iostream>
#include <exception>

#include <ex03/AForm.hpp>
#include <ex03/PresidentialPardonForm.hpp>
#include <ex03/RobotomyRequestForm.hpp>
#include <ex03/ShrubberyCreationForm.hpp>
#include <toolbox/color.hpp>
#include <toolbox/stepmark.hpp>

namespace {

AForm* createShrubberyCreationForm(const std::string& target) {
    std::stringstream logMsg;
    logMsg << "Creating ShrubberyCreationForm with target: " << target;
    toolbox::logger::StepMark::trace(logMsg.str());
    return new ShrubberyCreationForm(target);
}

AForm* createRobotomyRequestForm(const std::string& target) {
    std::stringstream logMsg;
    logMsg << "Creating RobotomyRequestForm with target: " << target;
    toolbox::logger::StepMark::trace(logMsg.str());
    return new RobotomyRequestForm(target);
}

AForm* createPresidentialPardonForm(const std::string& target) {
    std::stringstream logMsg;
    logMsg << "Creating PresidentialPardonForm with target: " << target;
    return new PresidentialPardonForm(target);
}

}  // namespace

Intern::Intern() {
    std::stringstream logMsg;
    logMsg << "Intern created";
    toolbox::logger::StepMark::debug(logMsg.str());
}

Intern::Intern(const Intern& src) {
    std::stringstream logMsg;
    logMsg << "Intern copy created";
    toolbox::logger::StepMark::debug(logMsg.str());
    (void)src;
}

Intern& Intern::operator=(const Intern& rhs) {
    std::stringstream logMsg;
    logMsg << "Intern assignment operator called";
    toolbox::logger::StepMark::debug(logMsg.str());
    (void)rhs;
    return *this;
}

Intern::~Intern() {
    std::stringstream logMsg;
    logMsg << "Intern destroyed";
    toolbox::logger::StepMark::debug(logMsg.str());
}

AForm* Intern::makeForm(const std::string& formName,
    const std::string& target) {
    std::stringstream logMsg;
    logMsg << "Intern::makeForm called with formName: " << formName
        << ", target: " << target;
    toolbox::logger::StepMark::info(logMsg.str());
    for (size_t i = 0; i < formInfosSize; ++i) {
        if (formName == formInfos[i].name) {
            AForm* newFormPtr = formInfos[i].create(target);
            std::cout << "Intern creates "
                << toolbox::color::green << formName
                << toolbox::color::reset
                << std::endl;
            return newFormPtr;
        }
    }
    logMsg.clear();
    logMsg.str("");
    logMsg << "Intern could not create form: " << formName;
    toolbox::logger::StepMark::error(logMsg.str());
    std::cerr << toolbox::color::red << "Intern couldn't create form: "
        << toolbox::color::red << formName
        << toolbox::color::reset << "\n"
        << toolbox::color::red << "Form not found, returning `NULL'"
        << toolbox::color::reset << "\n"
        << toolbox::color::reset << "The available forms are follows:"
        << std::endl;
    for (size_t i = 0; i < formInfosSize; ++i) {
        std::cerr << "- "
            << toolbox::color::green << formInfos[i].name
            << toolbox::color::reset
            << std::endl;
    }
    return NULL;
}

const Intern::FormInfo Intern::formInfos[] = {
    {"shrubbery creation", createShrubberyCreationForm},
    {"robotomy request", createRobotomyRequestForm},
    {"presidential pardon", createPresidentialPardonForm}
};

const size_t Intern::formInfosSize = sizeof(formInfos) /
    sizeof(Intern::FormInfo);
