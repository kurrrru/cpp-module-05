#pragma once

#include <string>
#include <iostream>
#include <exception>

#include <ex02/AForm.hpp>

class RobotomyRequestForm : public AForm {
 public:
    RobotomyRequestForm();
    explicit RobotomyRequestForm(const std::string& target);
    RobotomyRequestForm(const RobotomyRequestForm& src);
    RobotomyRequestForm& operator=(const RobotomyRequestForm& rhs);
    virtual ~RobotomyRequestForm();

    virtual void execute(const Bureaucrat& executor) const;

 private:
    const std::string _target;
};
