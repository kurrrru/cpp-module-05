#pragma once

#include <string>
#include <iostream>
#include <exception>

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

    class GradeInvalidException : public std::exception {
     public:
        explicit GradeInvalidException(
            const std::string& message = "Grade is invalid");
        virtual const char* what() const throw();
        virtual ~GradeInvalidException() throw();
     private:
        std::string _message;
    };

    class GradeTooHighException : public GradeInvalidException {
     public:
        explicit GradeTooHighException(
            const std::string& message = "Grade is too high");
        virtual ~GradeTooHighException() throw();
    };

    class GradeTooLowException : public GradeInvalidException {
     public:
        explicit GradeTooLowException(
            const std::string& message = "Grade is too low");
        virtual ~GradeTooLowException() throw();
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
