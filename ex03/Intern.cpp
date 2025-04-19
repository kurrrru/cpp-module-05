#include "Intern.hpp"

#include <string>
#include <iostream>
#include <exception>

#include "AForm.hpp"
#include "PresidentialPardonForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "ShrubberyCreationForm.hpp"

namespace {
namespace color {
const char red[] = "\033[1;31m";
const char green[] = "\033[1;32m";
const char yellow[] = "\033[1;33m";
const char blue[] = "\033[1;34m";
const char magenta[] = "\033[1;35m";
const char cyan[] = "\033[1;36m";
const char reset[] = "\033[0m";
}

AForm* createShrubberyCreationForm(const std::string& target) {
    return new ShrubberyCreationForm(target);
}

AForm* createRobotomyRequestForm(const std::string& target) {
    return new RobotomyRequestForm(target);
}

AForm* createPresidentialPardonForm(const std::string& target) {
    return new PresidentialPardonForm(target);
}

}  // namespace

Intern::Intern() {
}

Intern::Intern(const Intern& src) {
    (void)src;
}

Intern& Intern::operator=(const Intern& rhs) {
    (void)rhs;
    return *this;
}

Intern::~Intern() {
}

AForm* Intern::makeForm(const std::string& formName,
    const std::string& target) {
    for (size_t i = 0; i < formInfosSize; ++i) {
        if (formName == formInfos[i].name) {
            AForm* newFormPtr = formInfos[i].create(target);
            std::cout << "Intern creates "
                << color::green << formName << color::reset
                << std::endl;
            return newFormPtr;
        }
    }
    std::cerr << color::red
        << "Intern couldn't create form: " << formName << color::reset
        << std::endl;
    std::cerr << color::red
        << "Form not found, returning `NULL'" << color::reset
        << std::endl;
    std::cerr << "The available forms are follows:" << std::endl;
    for (size_t i = 0; i < formInfosSize; ++i) {
        std::cerr << "- " << color::cyan << formInfos[i].name << color::reset
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