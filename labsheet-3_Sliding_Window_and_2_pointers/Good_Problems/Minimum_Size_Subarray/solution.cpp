#include <vector>
#include <climits>

using namespace std;

class Solution
{
public:
    int minSubArrayLen(int target, vector<int> &nums)
    {
        // approach is  simple make a sliding window of variable size
        // if sum is less than target increase the window
        // if sum is more that the target decrease the window from behind
        // if sum is equal to target compare it with min and update min if required
        int head = 0;
        int tail = 0;
        int sum = nums[0];
        int minLen = INT_MAX;

        while (tail < nums.size())
        {
            if (sum < target)
            {
                tail++;
                if (tail < nums.size())
                {
                    sum += nums[tail];
                }
            }
            else
            {
                int size = tail - head + 1;
                minLen = min(minLen, size);

                sum -= nums[head];
                head++;
            }
        }

        // If minLen is still INT_MAX, no subarray is found
        return (minLen == INT_MAX) ? 0 : minLen;
    }
};
