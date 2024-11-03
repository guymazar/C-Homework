#include "homework_17.h"

int main() {
    std::string fileName = "text.txt";  // Replace with the name of your text file

    // Read the file
    std::vector<char> book = readBook(fileName);

    if (book.empty()) {
        std::cerr << "Failed to read the book." << std::endl;
        return 1;
    }

    // Compute word frequencies
    auto wordFrequency = computeWordFrequency(book);

    // Count unique words
    int uniqueWords = countUniqueWords(book);
    std::cout << "Total unique words: " << uniqueWords << std::endl;

    // Sort frequencies
    auto sortedFrequencies = sortFrequencies(wordFrequency);

    // Write frequencies to file
    writeFrequenciesToFile(sortedFrequencies, "output.txt");

    // Print hapax legomena (words that occur only once)
    printHapaxLegomena(sortedFrequencies);

    return 0;
}