#include <vector>

class Solution
{
public:
    vector<vector<int>> permute(vector<int> &nums)
    {
        vector<vector<int>> ans;

        if (nums.size() == 1)
        {
            return {nums};
        }
        else
        {
            for (int i = 0; i < nums.size(); i++)
            {
                int current = nums[i];

                // Erase the current element
                nums.erase(nums.begin() + i);

                // Recursively generate permutations for the remaining elements
                auto res = permute(nums);

                // Insert the current element back at its original position
                nums.insert(nums.begin() + i, current);

                // Append each permutation to the result
                for (const auto &perm : res)
                {
                    vector<int> temp = {current};
                    temp.insert(temp.end(), perm.begin(), perm.end());
                    ans.push_back(temp);
                }
            }
        }

        return ans;
    }
};
