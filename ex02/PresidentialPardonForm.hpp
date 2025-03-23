#pragma once

#include <string>
#include <iostream>
#include <exception>

#include "AForm.hpp"

class PresidentialPardonForm : public AForm {
 public:
    PresidentialPardonForm();
    explicit PresidentialPardonForm(const std::string& target);
    PresidentialPardonForm(const PresidentialPardonForm& src);
    PresidentialPardonForm& operator=(const PresidentialPardonForm& rhs);
    virtual ~PresidentialPardonForm();

    virtual void execute(const Bureaucrat& executor) const;

    class PardonException : public std::exception {
     public:
        virtual const char* what() const throw();
    };

 private:
    const std::string _target;
};
