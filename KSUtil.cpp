#include "KSUtil.hpp"
#include <string>

using namespace std;

bool isValidKanaKani(const string &input)
{
  std::setlocale(LC_ALL, ""); // Set locale for proper character classification

  // Convert string to wstring for easier character handling
  std::wstring wstr(input.begin(), input.end());

  const std::wstring validHiraganaRange = L"\u3040-\u309F"; // Hiragana characters
  const std::wstring validKatakanaRange = L"\u30A0-\u30FF"; // Katakana characters
  const std::wstring validKanjiRange = L"\u4E00-\u9FFF";    // Common Kanji range

  for (auto c : wstr)
  {
    if (!iswalnum(c) && // Check for alphanumeric characters (avoid Romaji)
        !(wstr.find(validHiraganaRange, c) != std::string::npos ||
          wstr.find(validKatakanaRange, c) != std::string::npos ||
          wstr.find(validKanjiRange, c) != std::string::npos))
    {
      return false; // Invalid character found
    }
  }
  return true;
}