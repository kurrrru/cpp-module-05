#pragma once

#include <string>
#include <iostream>
#include <exception>

#include <ex03/AForm.hpp>

class PresidentialPardonForm : public AForm {
 public:
    PresidentialPardonForm();
    explicit PresidentialPardonForm(const std::string& target);
    PresidentialPardonForm(const PresidentialPardonForm& src);
    PresidentialPardonForm& operator=(const PresidentialPardonForm& rhs);
    virtual ~PresidentialPardonForm();

    virtual void execute(const Bureaucrat& executor) const;

 private:
    const std::string _target;
};
