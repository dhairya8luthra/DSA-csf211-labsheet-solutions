class Solution
{
public:
    int lengthOfLongestSubstring(string s)
    {
        unordered_map<char, int> umap;
        int longest = 0;
        int current = 0;
        int current_l = 0;

        for (int i = 0; i < s.size(); i++)
        {
            if (umap.find(s[i]) == umap.end() || umap[s[i]] < current)
            {
                umap[s[i]] = i;
                current_l = i - current + 1;
            }
            else
            {
                current = umap[s[i]] + 1;
                current_l = i - current + 1;
                umap[s[i]] = i;
            }

            if (current_l > longest)
            {
                longest = current_l;
            }
        }

        return longest;
    }
};
