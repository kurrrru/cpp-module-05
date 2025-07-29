#pragma once

#include <string>
#include <iostream>
#include <exception>

#include <ex02/Bureaucrat.hpp>

class Bureaucrat;

class AForm {
 public:
    AForm();
    AForm(const std::string& name, int gradeToSign, int gradeToExecute);
    AForm(const AForm& src);
    AForm& operator=(const AForm& rhs);
    virtual ~AForm();

    std::string getName() const;
    bool getSigned() const;
    int getGradeToSign() const;
    int getGradeToExecute() const;
    bool beSigned(const Bureaucrat& bureaucrat);
    virtual void execute(const Bureaucrat& executor) const = 0;

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

    class FormNotSignedException : public std::exception {
     public:
        explicit FormNotSignedException(
            const std::string& message = "Form is not signed");
        virtual const char* what() const throw();
        virtual ~FormNotSignedException() throw();
     private:
        std::string _message;
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

std::ostream& operator<<(std::ostream& os, const AForm& form);
