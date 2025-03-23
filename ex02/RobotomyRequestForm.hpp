#pragma once

#include <string>
#include <iostream>
#include <exception>

#include "AForm.hpp"

class RobotomyRequestForm : public AForm {
 public:
    RobotomyRequestForm();
    explicit RobotomyRequestForm(const std::string& target);
    RobotomyRequestForm(const RobotomyRequestForm& src);
    RobotomyRequestForm& operator=(const RobotomyRequestForm& rhs);
    virtual ~RobotomyRequestForm();

    virtual void execute(const Bureaucrat& executor) const;

    class RobotomizeException : public std::exception {
     public:
        virtual const char* what() const throw();
    };

 private:
    const std::string _target;
};
