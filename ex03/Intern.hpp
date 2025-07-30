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

 private:
    struct FormInfo {
        const char* name;
        AForm* (*create)(const std::string&);
    };
    static const FormInfo formInfos[];
    static const size_t formInfosSize;
};
