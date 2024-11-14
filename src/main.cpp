#include "../include/Scop.h"

int main(int argc, char** argv) {
    if (argc != 2) {
        std::cerr << "Usage: " << argv[0] << " <some_argument>" << std::endl;
        return EXIT_FAILURE;
    }
    std::cout << "Validating file.." << std::endl;
    if (validateFile(argv[1])) {
        std::cout << "File " << argv[1] << " is valid" << std::endl;
    } else {
        std::cerr << "File " << argv[1] << " is invalid" << std::endl;
        return EXIT_FAILURE;
    }
    std::cout << "\033[1;32mSuccess\033[0m" << std::endl;
    Object obj;
    obj.filename = argv[1];

    obj.countVerticesAndFaces();
    obj.saveVertices();
    obj.saveFaces();
    obj.saveTexture();
    obj.centerObject();

    if(!glfwInit()){
        std::cerr << "Failed to initialize GLFW" << std::endl;
        return -1;
    }

    obj.startWin();
    obj.scopLoop();
}
