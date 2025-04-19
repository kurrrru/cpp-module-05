#include "ShrubberyCreationForm.hpp"

#include <fstream>
#include <iostream>
#include <string>
#include <cstdlib>
#include <ctime>

namespace {
namespace color {
const char red[] = "\033[1;31m";
const char green[] = "\033[1;32m";
const char yellow[] = "\033[1;33m";
const char blue[] = "\033[1;34m";
const char magenta[] = "\033[1;35m";
const char cyan[] = "\033[1;36m";
const char reset[] = "\033[0m";
}
}  // namespace

ShrubberyCreationForm::ShrubberyCreationForm()
    : AForm("Shrubbery Creation", 145, 137), _target("default") {
}

ShrubberyCreationForm::ShrubberyCreationForm(const std::string& target)
    : AForm("Shrubbery Creation", 145, 137), _target(target) {
}

ShrubberyCreationForm::ShrubberyCreationForm(const ShrubberyCreationForm& src)
    : AForm(src), _target(src._target) {
}

ShrubberyCreationForm& ShrubberyCreationForm::operator=
    (const ShrubberyCreationForm& rhs) {
    if (this != &rhs) {
        AForm::operator=(rhs);
    }
    return *this;
}

ShrubberyCreationForm::~ShrubberyCreationForm() {
}

void ShrubberyCreationForm::execute(const Bureaucrat& executor) const {
    AForm::execute(executor);
    std::string filename = _target + "_shrubbery";
    std::ofstream file(filename.c_str());
    if (!file.is_open()) {
        throw FileCreationException();
    }

    std::srand(std::time(NULL));
    const int maxTreeSize = 10;
    const int treeSize = std::rand() % (maxTreeSize - 2) + 3;
    for (int i = 0; i < treeSize; i++) {
        for (int j = 0; j < treeSize - i - 1; j++) {
            file << " ";
        }
        for (int j = 0; j < i * 2 + 1; j++) {
            file << "/";
        }
        file << "\\" << std::endl;
    }
    for (int i = 0; i < 2; i++) {
        for (int j = 0; j < treeSize - 1; j++) {
            file << " ";
        }
        file << "||" << std::endl;
    }

    file.close();
}

const char* ShrubberyCreationForm::FileCreationException::what() const throw() {
    return "File creation failed";
}
