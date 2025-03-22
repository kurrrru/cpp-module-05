#pragma once

#include <string>
#include <iostream>
#include <exception>

#include "Bureaucrat.hpp"

class Bureaucrat;

class Form {
 public:
    Form();
    Form(const std::string& name, int gradeToSign, int gradeToExecute);
    Form(const Form& src);
    Form& operator=(const Form& rhs);
    ~Form();

    std::string getName() const;
    bool getSigned() const;
    int getGradeToSign() const;
    int getGradeToExecute() const;
    bool beSigned(const Bureaucrat& bureaucrat);

    class GradeTooHighException : public std::exception {
     public:
        virtual const char* what() const throw();
    };

    class GradeTooLowException : public std::exception {
     public:
        virtual const char* what() const throw();
    };

 private:
    class Grade {
     public:
        Grade();
        explicit Grade(int grade);
        Grade(const Grade& src);
        Grade& operator=(const Grade& rhs);
        ~Grade();
        int getGrade() const;

     private:
        static const int _maxGrade = 1;
        static const int _minGrade = 150;
        int _grade;
    };
    const std::string _name;
    bool _signed;
    const Grade _gradeToSign;
    const Grade _gradeToExecute;
};

std::ostream& operator<<(std::ostream& os, const Form& form);
