#pragma once

#include <string>
#include <iostream>
#include <exception>

#include <ex02/AForm.hpp>

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
        explicit FileCreationException(
            const std::string& message = "Failed to create file");
        virtual const char* what() const throw();
        virtual ~FileCreationException() throw();
     private:
        std::string _message;
    };

 private:
    const std::string _target;
};
