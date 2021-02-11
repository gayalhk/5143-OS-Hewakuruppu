#include <iostream>
#include <string>
#include <stdio.h>

int main() {
    FILE *f = NULL;
    std::string command;
    std::string filename("main.cpp");    // insert name of file name
    int n = 0;

    command = "wc -l " + filename;
    f = popen(command.c_str(), "r");
    fscanf(f, "%d", &n);
    pclose(f);
    std::cout << "Number of lines: " << n << '\n';
}
