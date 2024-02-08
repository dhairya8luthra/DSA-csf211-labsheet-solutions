#include <vector>

class Solution
{
public:
    char nextGreatestLetter(std::vector<char> &letters, char target)
    {
        int high = letters.size() - 1;
        int low = 0;
        int mid;
        char result = letters[0];

        while (low <= high)
        {
            mid = low + (high - low) / 2;
            if (letters[mid] == target)
            {
                if (mid != letters.size() - 1)
                {
                    low = mid + 1;
                }
                else
                {
                    return letters[0];
                }
            }
            else if (letters[mid] > target)
            {
                result = letters[mid];
                high = mid - 1;
            }
            
            else
            {
                low = mid + 1;
            }
        }
        return result;
    }
};
