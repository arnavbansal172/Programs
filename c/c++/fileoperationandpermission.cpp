#include <iostream>
#include <fstream>
#include <sys/stat.h>

int main() {
    const char* filename = "example.txt";

    // Writing to a File
    std::ofstream outputFile(filename);
    if (outputFile.is_open()) {
        outputFile << "Hello, File!\n";
        outputFile.close();
        std::cout << "File '" << filename << "' written successfully.\n";
    } else {
        std::cerr << "Unable to open the file for writing.\n";
        return 1; // Exit with an error code
    }

    // Setting File Permissions
    int result = chmod(filename, S_IRUSR | S_IWUSR | S_IRGRP | S_IROTH);

    if (result == 0) {
        std::cout << "File permissions set successfully.\n";
    } else {
        std::cerr << "Error setting file permissions.\n";
        return 1; // Exit with an error code
    }

    // Reading from a File
    std::ifstream inputFile(filename);
    if (inputFile.is_open()) {
        std::cout << "Contents of the file '" << filename << "':\n";

        std::string line;
        while (std::getline(inputFile, line)) {
            std::cout << line << '\n';
        }

        inputFile.close();
    } else {
        std::cerr << "Unable to open the file for reading.\n";
        return 1; // Exit with an error code
    }

    return 0; // Exit successfully
}
