#pragma once

#include <iostream>
#include <fstream>
#include <vector>
#include <string>
#include <sstream>
#include <map>
#include <set>
#include <functional>

// Reads the contents of a file and returns a vector of alphabetic characters,
// replacing non-alphabetic characters with spaces.
std::vector<char> readBook(const std::string& fileName);

// Computes the frequency of each word in the book.
std::map<std::string, int> computeWordFrequency(const std::vector<char>& book);

// Counts the number of unique words in the book.
int countUniqueWords(const std::vector<char>& book);

// Sorts word frequencies in descending order.
std::multimap<int, std::string, std::greater<>> sortFrequencies(const std::map<std::string, int>& frequencies);

// Writes the sorted word frequencies to a file.
void writeFrequenciesToFile(const std::multimap<int, std::string, std::greater<>>& sortedFrequencies, const std::string& filename);

// Prints the number of hapax legomena (words that occur only once) and some examples.
void printHapaxLegomena(const std::multimap<int, std::string, std::greater<>>& sortedFrequencies);