#include <iostream>
#include "KSUtil.cpp"

int main()
{
    std::cout << "Hello, World!" << std::endl;
    std::cout << isValidKanaKanji("重ねる") << std::endl;
    std::cout << isValidKanaKanji("る") << std::endl;
    std::cout << isValidKanaKanji("t") << std::endl;
    std::cout << isAlt("重ねる") << std::endl;
    std::cout << isAlt("る") << std::endl;
    std::cout << isAlt("t") << std::endl;
    return 0;
}

// TODO - Add a ks config file in yaml that specifies settings
// One setting might be to clarify what counts as an indent?