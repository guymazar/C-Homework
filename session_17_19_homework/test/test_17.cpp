#include <gtest/gtest.h>
#include <vector>
#include <string>
#include <map>
#include <sstream>
#include <functional>
#include "homework_17.h"  

// Test readBook function
TEST(ReadBookTest, ReadsAlphabeticCharacters) {
    std::string testContent = "Hello, world! This is a test.";
    std::ofstream outFile("test_file.txt");
    outFile << testContent;
    outFile.close();

    std::vector<char> expectedChars = {'h', 'e', 'l', 'l', 'o', ' ', 'w', 'o', 'r', 'l', 'd', ' ',
                                       't', 'h', 'i', 's', ' ', 'i', 's', ' ', 'a', ' ', 't', 'e', 's', 't'};
    auto result = readBook("test_file.txt");

    ASSERT_EQ(result, expectedChars);
    std::remove("test_file.txt");  // Clean up the file
}

// Test computeWordFrequency function
TEST(ComputeWordFrequencyTest, CountsWordsCorrectly) {
    std::vector<char> bookContent = {'t', 'e', 's', 't', ' ', 't', 'e', 's', 't', ' ', 'o', 'n', 'e', ' ', 't', 'w', 'o'};
    std::map<std::string, int> expectedFrequencies = {{"test", 2}, {"one", 1}, {"two", 1}};
    
    auto result = computeWordFrequency(bookContent);

    ASSERT_EQ(result, expectedFrequencies);
}

// Test countUniqueWords function
TEST(CountUniqueWordsTest, CountsUniqueWords) {
    std::vector<char> bookContent = {'t', 'e', 's', 't', ' ', 't', 'e', 's', 't', ' ', 'o', 'n', 'e', ' ', 't', 'w', 'o'};
    int expectedCount = 3;
    
    int result = countUniqueWords(bookContent);

    ASSERT_EQ(result, expectedCount);
}

// Test sortFrequencies function
TEST(SortFrequenciesTest, SortsByFrequencyCorrectly) {
    std::map<std::string, int> wordFrequencies = {{"test", 2}, {"one", 1}, {"two", 1}};
    std::multimap<int, std::string, std::greater<>> expectedSortedFrequencies = {
        {2, "test"},
        {1, "one"},
        {1, "two"}
    };

    auto result = sortFrequencies(wordFrequencies);

    ASSERT_EQ(result, expectedSortedFrequencies);
}

// Test printHapaxLegomena function (to verify it identifies hapax legomena)
TEST(PrintHapaxLegomenaTest, IdentifiesHapaxLegomenaCorrectly) {
    std::map<std::string, int> wordFrequencies = {{"test", 2}, {"one", 1}, {"two", 1}};
    auto sortedFrequencies = sortFrequencies(wordFrequencies);
    
    testing::internal::CaptureStdout();
    printHapaxLegomena(sortedFrequencies);
    std::string output = testing::internal::GetCapturedStdout();

    EXPECT_TRUE(output.find("Number of hapax legomena (words that occur only once): 2") != std::string::npos);
    EXPECT_TRUE(output.find("one") != std::string::npos);
    EXPECT_TRUE(output.find("two") != std::string::npos);
}

