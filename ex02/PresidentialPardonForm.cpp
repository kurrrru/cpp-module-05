#include "PresidentialPardonForm.hpp"

#include <iostream>
#include <string>

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
}  // namespace

PresidentialPardonForm::PresidentialPardonForm()
    : AForm("Presidential Pardon", 25, 5), _target("default") {
}

PresidentialPardonForm::PresidentialPardonForm(const std::string& target)
    : AForm("Presidential Pardon", 25, 5), _target(target) {
}

PresidentialPardonForm::PresidentialPardonForm
    (const PresidentialPardonForm& src) : AForm(src), _target(src._target) {
}

PresidentialPardonForm& PresidentialPardonForm::operator=
    (const PresidentialPardonForm& rhs) {
    if (this != &rhs) {
        AForm::operator=(rhs);
    }
    return *this;
}

PresidentialPardonForm::~PresidentialPardonForm() {
}

void PresidentialPardonForm::execute(const Bureaucrat& executor) const {
    AForm::execute(executor);
    std::cout << color::green << _target << color::reset
        << " has been pardoned by Zaphod Beeblebrox" << std::endl;
}
