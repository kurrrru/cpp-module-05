#pragma once

#include <string>
#include <iostream>
#include <exception>

#include "AForm.hpp"

class AForm;

class Bureaucrat {
 public:
    Bureaucrat();
    Bureaucrat(const std::string& name, int grade);
    Bureaucrat(const Bureaucrat& src);
    Bureaucrat& operator=(const Bureaucrat& rhs);
    ~Bureaucrat();

    std::string getName() const;
    int getGrade() const;
    void incrementGrade();
    void decrementGrade();
    void signForm(AForm& form);
    void executeForm(const AForm& form);

    class GradeTooHighException : public std::exception {
     public:
        virtual const char* what() const throw();
    };

    class GradeTooLowException : public std::exception {
     public:
        virtual const char* what() const throw();
    };

 private:
    const std::string _name;
    class Grade {
     public:
        Grade();
        explicit Grade(int grade);
        Grade(const Grade& src);
        Grade& operator=(const Grade& rhs);
        ~Grade();
        int getGrade() const;
        void increment();
        void decrement();

     private:
        static const int _maxGrade = 1;
        static const int _minGrade = 150;
        int _grade;
    } _grade;
};

std::ostream& operator<<(std::ostream& os, const Bureaucrat& bureaucrat);
