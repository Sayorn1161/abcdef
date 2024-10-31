#include <iostream>
#include <fstream>
#include <string>
#include <vector>

void compareFiles(const std::string& file1, const std::string& file2) {
    std::ifstream in1(file1);
    std::ifstream in2(file2);
    std::string line1, line2;

    if (in1.is_open() && in2.is_open()) {
        while (std::getline(in1, line1) && std::getline(in2, line2)) {
            if (line1 != line2) {
                std::cout << "Mismatch: " << line1 << " != " << line2 << "\n";
            }
        }
    }

    in1.close();
    in2.close();
}

int main() {
    compareFiles("input1.txt", "input2.txt");
    return 0;
}
