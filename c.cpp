#include <iostream>
#include <fstream>
#include <string>

void addDashesAfterLastNonSpaceLine(const std::string& inputFile, const std::string& outputFile) {
    std::ifstream in(inputFile);
    std::ofstream out(outputFile);
    std::string line;
    std::string lastNonSpaceLine;
    bool foundNonSpaceLine = false;

    if (in.is_open() && out.is_open()) {
        while (std::getline(in, line)) {
            out << line << "\n";
            if (line.find(' ') == std::string::npos && !line.empty()) {
                lastNonSpaceLine = line;
                foundNonSpaceLine = true;
            }
        }
        if (foundNonSpaceLine) {
            out << "------------" << "\n";
        }
    }

    in.close();
    out.close();
}

int main() {
    addDashesAfterLastNonSpaceLine("input.txt", "output3.txt");
    return 0;
}
