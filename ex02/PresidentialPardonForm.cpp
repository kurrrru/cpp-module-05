#include <ex02/PresidentialPardonForm.hpp>

#include <iostream>
#include <sstream>
#include <string>

#include <toolbox/color.hpp>
#include <toolbox/stepmark.hpp>

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
    std::cout << toolbox::color::green << _target
        << toolbox::color::reset << " has been pardoned by Zaphod Beeblebrox"
        << std::endl;
}
