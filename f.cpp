#include <iostream>
#include <fstream>
#include <string>

void caesarCipher(const std::string& inputFile, const std::string& outputFile, int key) {
    std::ifstream in(inputFile);
    std::ofstream out(outputFile);
    std::string line;

    if (in.is_open() && out.is_open()) {
        while (std::getline(in, line)) {
            for (char& ch : line) {
                if (std::isalpha(ch)) {
                    char base = std::isupper(ch) ? 'A' : 'a';
                    ch = (ch - base + key) % 26 + base;
                }
            }
            out << line << "\n";
        }
    }

    in.close();
    out.close();
}

int main() {
    caesarCipher("input.txt", "encrypted.txt", 3);
    return 0;
}
