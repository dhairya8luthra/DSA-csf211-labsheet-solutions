#include <vector>

class Solution
{
public:
    double findMaxAverage(std::vector<int> &nums, int k)
    {
        double window_start = 0;
        double window_end = k - 1;
        double sum_curr = 0;
        double avg = 0;

        // Calculate the initial sum of the first 'k' elements
        for (int i = 0; i <= window_end; i++)
        {
            sum_curr += nums[i];
        }

        double avg_curr = sum_curr / k;
        avg = avg_curr;

        // Sliding window approach
        while (window_end < nums.size() - 1)
        {
            window_end++;
            sum_curr += nums[window_end] - nums[window_start];

            avg_curr = sum_curr / k;

            if (avg_curr > avg)
            {
                avg = avg_curr;
            }

            window_start++;
        }

        return avg;
    }
};
