#include <iostream>
#include <fstream>
#include <vector>
#include <string>
#include <sstream>
#include <algorithm>
#include <iterator>
#include <cctype>

// Function to read the file and filter alphabetic characters
std::vector<char> readBook(const std::string& fileName) {
    std::vector<char> alphabeticChars;
    std::ifstream file(fileName);

    if (!file.is_open()) {
        std::cerr << "Error opening file" << std::endl;
        return alphabeticChars;
    }

    char ch;
    while (file.get(ch)) {
        if (std::isalpha(ch)) {
            alphabeticChars.push_back(std::tolower(ch));  // Add lowercase alphabetic character to vector
        } else {
            alphabeticChars.push_back(' ');  // Replace non-alphabetic character with space
        }
    }

    file.close();
    return alphabeticChars;
}

// Function to split vector<char> into vector<string> of words
std::vector<std::string> splitIntoWords(const std::vector<char>& book) {
    std::string content(book.begin(), book.end());
    std::istringstream ss(content);
    std::vector<std::string> words;
    std::string word;

    while (ss >> word) {
        words.push_back(word);
    }
    return words;
}

// Function to calculate word frequencies and sort them in descending order
std::vector<std::pair<int, std::string>> computeSortedWordFrequencies(std::vector<std::string>& words) {
    std::vector<std::pair<int, std::string>> wordFrequencies;

    // Sort words alphabetically to prepare for counting
    std::sort(words.begin(), words.end());

    // Use unique algorithm to count occurrences and store them in wordFrequencies
    auto it = words.begin();
    while (it != words.end()) {
        auto range = std::equal_range(it, words.end(), *it);
        int count = std::distance(range.first, range.second);
        wordFrequencies.emplace_back(count, *it);
        it = range.second;
    }

    // Sort by frequency in descending order
    std::sort(wordFrequencies.begin(), wordFrequencies.end(), std::greater<>());
    return wordFrequencies;
}

// Function to write sorted word frequencies to a file
void writeFrequenciesToFile(const std::vector<std::pair<int, std::string>>& sortedFrequencies, const std::string& filename) {
    std::ofstream outFile(filename);
    if (!outFile.is_open()) {
        std::cerr << "Error opening file for writing: " << filename << std::endl;
        return;
    }

    int rank = 1;
    for (const auto& entry : sortedFrequencies) {
        outFile << rank << " " << entry.first << " " << entry.second << std::endl;
        ++rank;
    }

    outFile.close();
    std::cout << "Frequencies written to " << filename << std::endl;
}

// Function to print hapax legomena (words that occur only once)
void printHapaxLegomena(const std::vector<std::pair<int, std::string>>& sortedFrequencies) {
    int hapaxCount = 0;
    std::cout << "Hapax Legomena (words that occur only once):" << std::endl;

    for (const auto& entry : sortedFrequencies) {
        if (entry.first == 1) {
            ++hapaxCount;
            if (hapaxCount <= 10) {  // Print up to 10 examples
                std::cout << entry.second << std::endl;
            }
        }
    }

    std::cout << "Total number of hapax legomena: " << hapaxCount << std::endl;
}

int main() {
    std::string fileName = "text.txt";  // Replace with your actual file name
    std::vector<char> book = readBook(fileName);

    if (book.empty()) {
        std::cerr << "Failed to read the book." << std::endl;
        return 1;
    }

    // Split the characters into words
    std::vector<std::string> words = splitIntoWords(book);

    // Compute sorted word frequencies
    auto sortedFrequencies = computeSortedWordFrequencies(words);

    // Write frequencies to file
    writeFrequenciesToFile(sortedFrequencies, "output.txt");

    // Print hapax legomena
    printHapaxLegomena(sortedFrequencies);

    return 0;
}