#include <string>
#include <iostream>

#include "AForm.hpp"
#include "Intern.hpp"

int main() {
    std::string names[] = {
        "robotomy request",
        "shrubbery creation",
        "presidential pardon",
        "invalid form"
    };

    for (int i = 0; i < 4; ++i) {
        Intern someRandomIntern;
        AForm* rrf;
        rrf = someRandomIntern.makeForm(names[i], "Bender");
        if (rrf) {
            std::cout << *rrf << std::endl;
            delete rrf;
        }
    }
}
