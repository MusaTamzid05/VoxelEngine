#include <iostream>
#include "window.h"
#include "utils.h"


int main(int argc, char** argv) {
    std::string text = read_file("../src/main.cpp");
    std::cout << text << "\n";
    //Window window;
    //window.run();
    return 0;
}
