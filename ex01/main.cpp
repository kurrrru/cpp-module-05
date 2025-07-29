#include <iostream>
#include <string>
#include <sstream>
#include <exception>

#include <ex01/Bureaucrat.hpp>
#include <ex01/Form.hpp>
#include <toolbox/stepmark.hpp>
#include <toolbox/color.hpp>

int main(void) {
    toolbox::logger::StepMark::setLogFile("bureaucrat.log");
    toolbox::logger::StepMark::setLevel(toolbox::logger::INFO);
    try {
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
    } catch (const std::exception& e) {
        std::stringstream ss;
        ss << "Exception caught: " << e.what();
        toolbox::logger::StepMark::error(ss.str());
        std::cerr << toolbox::color::red << "Error: " << e.what()
                << toolbox::color::reset
                << std::endl;
    }
}
