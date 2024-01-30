
#include <iostream>

class Solution
{
public:
    int shipWithinDays(std::vector<int> &weights, int days)
    {
        int max = 0;
        int sum = 0;
        int n = weights.size();

        for (int i = 0; i < n; i++)
        {
            sum += weights[i];
            if (weights[i] > max)
            {
                max = weights[i];
            }
        }

        int low = max;
        int high = sum;
        int mid;
        while (low <= high)
        {
            mid = low + (high - low) / 2;
            int filledShip = 0;
            int day = 1;

            for (int j = 0; j < n; j++)
            {
                if (filledShip + weights[j] > mid)
                {
                    // If the current package can't fit in the current day, move to the next day
                    day++;
                    filledShip = 0;
                }
                filledShip += weights[j];
            }

            if (day <= days)
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