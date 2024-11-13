#include <iostream>
#include <fstream>

bool validateFile(const std::string& filename) {
    if (filename.size() < 4 || filename.substr(filename.size() - 4) != ".obj") {
        std::cerr << "Error: File " << filename << " does not have a .obj extension" << std::endl;
        return false;
    }
    
    std::ifstream file(filename);
    if (!file) {
        std::cerr << "Error: Cannot open file " << filename << std::endl;
        return false;
    }
    return true;
}
