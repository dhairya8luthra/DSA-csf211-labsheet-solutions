#include <vector>
#include <string>
#include <sstream>

class Solution
{
public:
    std::string reverseWords(std::string s)
    {
        std::vector<std::string> words;
        std::istringstream iss(s);

        // Split the input string into words
        while (iss >> s)
        {
            words.push_back(s);
        }

        // Reverse the order of words
        std::reverse(words.begin(), words.end());

        // Join the words back into a string with spaces
        std::string result;
        for (const auto &word : words)
        {
            result += word + " ";
        }

        // Remove the trailing space
        if (!result.empty())
        {
            result.pop_back();
        }

        return result;
    }
};