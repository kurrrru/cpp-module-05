#pragma once

#include <string>
#include <exception>

#include <ex03/AForm.hpp>

class AForm;

class Intern {
 public:
    Intern();
    Intern(const Intern& src);
    Intern& operator=(const Intern& rhs);
    ~Intern();

    AForm* makeForm(const std::string& formName, const std::string& target);

    class FormNotFoundException : public std::exception {
     public:
        explicit FormNotFoundException(
            const std::string& message = "Form not found");
        virtual const char* what() const throw();
        virtual ~FormNotFoundException() throw();
     private:
        std::string _message;
    };

 private:
    struct FormInfo {
        const char* name;
        AForm* (*create)(const std::string&);
    };
    static const FormInfo formInfos[];
    static const size_t formInfosSize;
};
