class Solution
{
public:
    int mySqrt(int x)
    {
        // Special cases
        if (x == 0 || x == 1)
            return x;

        int start = 0, end = x;
        int mid;
        int ans;

        // Binary search to find the integer part of the square root
        while (start <= end)
        {
            mid = start + (end - start) / 2;
            if (mid <= x / mid)
            {
                start = mid + 1;
                ans = mid;
            }
            else
            {
                end = mid - 1;
            }
        }

        return static_cast<int>(ans);
    }
};
