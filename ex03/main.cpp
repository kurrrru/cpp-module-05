#include <string>
#include <sstream>
#include <iostream>

#include <ex03/AForm.hpp>
#include <ex03/Intern.hpp>
#include <toolbox/color.hpp>
#include <toolbox/stepmark.hpp>

int main() {
    toolbox::logger::StepMark::setLogFile("bureaucrat.log");
    toolbox::logger::StepMark::setLevel(toolbox::logger::INFO);
    std::string names[] = {
        "robotomy request",
        "shrubbery creation",
        "presidential pardon",
        "invalid form"
    };

    for (int i = 0; i < 4; ++i) {
        try {
            Intern someRandomIntern;
            AForm* rrf;
            rrf = someRandomIntern.makeForm(names[i], "Bender");
            if (rrf) {
                std::cout << *rrf << std::endl;
                delete rrf;
            }
        } catch (const std::exception& e) {
            std::stringstream logMsg;
            logMsg << "Exception caught: " << e.what();
            toolbox::logger::StepMark::error(logMsg.str());
            std::cerr << toolbox::color::red << "Error: " << e.what()
                    << toolbox::color::reset
                    << std::endl;
        }
    }
}
