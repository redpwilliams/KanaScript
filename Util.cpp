#include "Util.hpp"
#include <string>
#include <algorithm>

using namespace std;

// Define valid character ranges (adjust as needed)
const std::string validHiraganaRange = "\u3040-\u309F";
const std::string validKatakanaRange = "\u30A0-\u30FF";
const std::string validKanjiRange = "\u4E00-\u9FFF";

bool isValidKanaKanji(const std::string& str)
{
    auto isValidChar = [&](char c) {
        // Check if character falls within a valid range
        return !(isalnum(c) && (
                str.find_first_of(validHiraganaRange) == std::string::npos &&
                str.find_first_of(validKatakanaRange) == std::string::npos &&
                str.find_first_of(validKanjiRange) == std::string::npos));
    };

    // Use std::all_of to check all characters
    return std::all_of(str.begin(), str.end(), isValidChar);
};