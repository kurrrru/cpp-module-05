#pragma once

#include <string>
#include <iostream>
#include <exception>

class Bureaucrat {
 public:
    Bureaucrat();
    Bureaucrat(const Bureaucrat& src);
    Bureaucrat& operator=(const Bureaucrat& rhs);
    ~Bureaucrat();

    Bureaucrat(const std::string& name, int grade);

    std::string getName() const;
    int getGrade() const;

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

     private:
        int _grade;
    } _grade;
};

std::ostream& operator<<(std::ostream& os, const Bureaucrat& bureaucrat);
