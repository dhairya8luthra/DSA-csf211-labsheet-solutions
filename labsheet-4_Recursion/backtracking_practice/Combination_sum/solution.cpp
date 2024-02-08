#include <bits/stdc++.h>
class Solution
{
public:
    void findCombination(int index, vector<vector<int>> &ans, vector<int> &ds, int target, vector<int> &candidates)
    {
        // base case
        if (index == candidates.size())
        {
            if (target == 0)
            {
                ans.push_back(ds);
            }
            return;
        }
        // pickup elements
        if (candidates[index] <= target)
        {
            ds.push_back(candidates[index]);
            findCombination(index, ans, ds, target - candidates[index], candidates);
            ds.pop_back();
        }
        findCombination(index + 1, ans, ds, target, candidates);
    }

public:
    vector<vector<int>> combinationSum(vector<int> &candidates, int target)
    {
        vector<vector<int>> ans;
        vector<int> ds;
        findCombination(0, ans, ds, target, candidates);
        return ans;
    }
};