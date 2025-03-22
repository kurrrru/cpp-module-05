#include <iostream>
#include <string>
#include <exception>

#include "Bureaucrat.hpp"
#include "Form.hpp"

int main(void) {
    Bureaucrat bureaucrats[5] = {
        Bureaucrat("best bureaucrat", 1),
        Bureaucrat("good bureaucrat", 50),
        Bureaucrat("okay bureaucrat", 75),
        Bureaucrat("bad bureaucrat", 100),
        Bureaucrat("worst bureaucrat", 150)
    };
    for (int i = 0; i < 5; i++) {
        Form forms[3] = {
            Form("hard form", 1, 1),
            Form("medium form", 75, 75),
            Form("easy form", 150, 150)
        };
        for (int j = 0; j < 3; j++) {
            bureaucrats[i].signForm(forms[j]);
        }
    }
}
