#include "KSUtil.hpp"
#include <string>
#include <algorithm>

using namespace std;

// Define valid character ranges (adjust as needed)
const std::string validHiraganaRange = "\u3040-\u309F";
const std::string validKatakanaRange = "\u30A0-\u30FF";
const std::string validKanjiRange = "\u4E00-\u9FFF";

bool isValidKanaKanji(const std::string &str)
{
  for (auto c : str)
  {
    // Check for alphanumeric characters (avoid Romaji)
    if (isalnum(c))
    {
      return false;
    }

    // Check if character falls within a valid range
    if (str.find_first_of(validHiraganaRange) == std::string::npos &&
        str.find_first_of(validKatakanaRange) == std::string::npos &&
        str.find_first_of(validKanjiRange) == std::string::npos)
    {
      return false;
    }
  }

  // If all characters are valid, return true
  return true;
}

bool isAlt(const std::string& str)
{
    auto isValidChar = [&](char c) {
        if (isalnum(c))
        {
            return false;
        }

        // Check if character falls within a valid range
        if (str.find_first_of(validHiraganaRange) == std::string::npos &&
            str.find_first_of(validKatakanaRange) == std::string::npos &&
            str.find_first_of(validKanjiRange) == std::string::npos)
        {
            return false;
        }
        return true;
    };

    // Use std::all_of to check all characters
    return std::all_of(str.begin(), str.end(), isValidChar);
        };