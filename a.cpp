#include <iostream>
#include <fstream>
#include <string>

void copyFile(const std::string& inputFile, const std::string& outputFile) {
    std::ifstream in(inputFile);
    std::ofstream out(outputFile);
    std::string line;

    if (in.is_open() && out.is_open()) {
        while (std::getline(in, line)) {
            out << line << "\n";
        }
    }

    in.close();
    out.close();
}

int main() {
    copyFile("input.txt", "output1.txt");
    return 0;
}
