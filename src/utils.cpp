#include "utils.h"
#include <fstream>
#include <iostream>


std::string read_file(const std::string& path) {
    std::ifstream input_file(path);

    if(!input_file.is_open()) {
        std::cerr << "Could not open " << path << "\n";
        exit(2);
    }

    std::string text = "";
    std::string line;

    while(std::getline(input_file, line)) 
        text += line + "\n";

    input_file.close();

    return text;

}
