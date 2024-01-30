#include <cmath>
class Solution
{
public:
    int minEatingSpeed(vector<int> &piles, int h)
    {
        int n = piles.size();
        int max_pile = 0;
        if (n == 1)
        {
            return ceil((double)piles[0] / h);
        }
        for (int i = 0; i < n; i++)
        {
            if (piles[i] > max_pile)
            {
                max_pile = piles[i];
            }
            else
            {
                continue;
            }
        }
        if (h == n)
        {
            return max_pile;
        }

        // now the maximum speed of koko could be max_pile
        // binary searching for the optimal speed from 1 to max_pile
        int high = max_pile;
        int low = 1;
        int mid;
        double time = 0;
        while (low <= high)
        {
            time = 0;
            mid = low + (high - low) / 2;
            for (double j = 0; j < n; j++)
            {
                time += ceil((double)piles[j] / mid);
            }
            if (time <= h)
            {
                high = mid - 1;
            }
            else
            {
                low = mid + 1;
            }
        }

        return low;
    }
};