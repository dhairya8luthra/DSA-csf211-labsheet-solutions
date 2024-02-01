class Solution
{
public:
    int longestOnes(vector<int> &nums, int k)
    {
        int window_start = 0;
        int window_end = 0;
        int count_zeroes = 0;
        int max_len = 0;

        while (window_end < nums.size())
        {
            if (nums[window_end] == 0)
            {
                count_zeroes++;
            }

            // Adjust window size
            while (count_zeroes > k)
            {
                if (nums[window_start] == 0)
                {
                    count_zeroes--;
                }
                window_start++;
            }

            // Update current window size
            int curr_len = window_end - window_start + 1;

            // Update maximum length
            max_len = max(max_len, curr_len);

            // Increment window_end
            window_end++;
        }

        return max_len;
    }
};
s