#include <iostream>
#include <fstream>
#include <string>
#include <cctype>

void generateStatistics(const std::string& inputFile, const std::string& outputFile) {
    std::ifstream in(inputFile);
    std::ofstream out(outputFile);
    std::string line;
    int charCount = 0, lineCount = 0, vowelCount = 0, consonantCount = 0, digitCount = 0;

    const std::string vowels = "aeiouAEIOU";

    if (in.is_open() && out.is_open()) {
        while (std::getline(in, line)) {
            ++lineCount;
            for (char ch : line) {
                ++charCount;
                if (std::isdigit(ch)) {
                    ++digitCount;
                } else if (std::isalpha(ch)) {
                    if (vowels.find(ch) != std::string::npos) {
                        ++vowelCount;
                    } else {
                        ++consonantCount;
                    }
                }
            }
        }
        out << "Кількість символів: " << charCount << "\n";
        out << "Кількість рядків: " << lineCount << "\n";
        out << "Кількість голосних букв: " << vowelCount << "\n";
        out << "Кількість приголосних букв: " << consonantCount << "\n";
        out << "Кількість цифр: " << digitCount << "\n";
    }

    in.close();
    out.close();
}

int main() {
    generateStatistics("input.txt", "stats.txt");
    return 0;
}
