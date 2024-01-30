// sliding window approach
// same approach could be used to solve the problem in labsheet as well
class Solution
{
public:
    int maxScore(vector<int> &cardPoints, int k)
    {
        int n = cardPoints.size();
        // the approach is going to be using 2 sliding windows
        // we create k length sliding window on one side and then if reduce the sizee of longer side and increase one side until we get max score
        int right_window_pointer = n - k;
        int left_window_pointer = -1;
        int max_sum = 0;
        int sum = 0;
        // initiating sum so it is easy to calculating without traversing again and again
        for (int i = right_window_pointer; i < n; i++)
        {
            sum += cardPoints[i];
        }
        max_sum = sum;
        // sliding the window
        while (right_window_pointer < n)
        {
            if (right_window_pointer < n)
            {
                sum += cardPoints[++left_window_pointer] - cardPoints[right_window_pointer++];
            }
            else
            {
                continue;
            }
            if (sum > max_sum)
            {
                max_sum = sum;
            }
        }
        return max_sum;
    }
};