#include "homework_17.h"

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
            alphabeticChars.push_back(ch);
        } else {
            alphabeticChars.push_back(' ');
        }
    }

    file.close();
    return alphabeticChars;
}

std::map<std::string, int> computeWordFrequency(const std::vector<char>& book) {
    std::map<std::string, int> wordFrequency;
    std::stringstream ss(std::string(book.begin(), book.end()));
    std::string word;

    while (ss >> word) {
        ++wordFrequency[word];
    }

    return wordFrequency;
}

int countUniqueWords(const std::vector<char>& book) {
    std::set<std::string> uniqueWords;
    std::stringstream ss(std::string(book.begin(), book.end()));
    std::string word;

    while (ss >> word) {
        uniqueWords.insert(word);
    }

    return uniqueWords.size();
}

std::multimap<int, std::string, std::greater<>> sortFrequencies(const std::map<std::string, int>& frequencies) {
    std::multimap<int, std::string, std::greater<>> sortedFrequencies;

    for (const auto& entry : frequencies) {
        sortedFrequencies.insert({entry.second, entry.first});
    }

    return sortedFrequencies;
}

void writeFrequenciesToFile(const std::multimap<int, std::string, std::greater<>>& sortedFrequencies, const std::string& filename) {
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

void printHapaxLegomena(const std::multimap<int, std::string, std::greater<>>& sortedFrequencies) {
    int hapaxCount = 0;
    std::vector<std::string> hapaxWords;

    for (const auto& entry : sortedFrequencies) {
        if (entry.first == 1) {
            hapaxWords.push_back(entry.second);
            ++hapaxCount;
        }
    }

    std::cout << "Number of hapax legomena (words that occur only once): " << hapaxCount << std::endl;
    std::cout << "Some examples of hapax legomena:" << std::endl;

    for (size_t i = 0; i < std::min<size_t>(hapaxWords.size(), 10); ++i) {
        std::cout << hapaxWords[i] << std::endl;
    }
}