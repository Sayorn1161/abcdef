#include <iostream>
#include <fstream>
#include <string>
#include <vector>

void copyFileReverse(const std::string& inputFile, const std::string& outputFile) {
    std::ifstream in(inputFile);
    std::ofstream out(outputFile);
    std::string line;
    std::vector<std::string> lines;

    if (in.is_open() && out.is_open()) {
        while (std::getline(in, line)) {
            lines.push_back(line);
        }
        for (auto it = lines.rbegin(); it != lines.rend(); ++it) {
            out << *it << "\n";
        }
    }

    in.close();
    out.close();
}

int main() {
    copyFileReverse("input.txt", "output2.txt");
    return 0;
}
