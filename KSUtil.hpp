#ifndef KSUtil_HPP
#define KSUtil_HPP

#include <locale>
#include <ctype.h> // for isalpha
#include <string>

using namespace std;

bool isValidKanaKanji(const string &input);
bool isAlt(const string &input);

#endif