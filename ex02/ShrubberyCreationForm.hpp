#pragma once

#include <string>
#include <iostream>
#include <exception>

#include "AForm.hpp"

class ShrubberyCreationForm : public AForm {
 public:
    ShrubberyCreationForm();
    explicit ShrubberyCreationForm(const std::string& target);
    ShrubberyCreationForm(const ShrubberyCreationForm& src);
    ShrubberyCreationForm& operator=(const ShrubberyCreationForm& rhs);
    virtual ~ShrubberyCreationForm();

    virtual void execute(const Bureaucrat& executor) const;

    class FileCreationException : public std::exception {
     public:
        virtual const char* what() const throw();
    };

 private:
    const std::string _target;
};
