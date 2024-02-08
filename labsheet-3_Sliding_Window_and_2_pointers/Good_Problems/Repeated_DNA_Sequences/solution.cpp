class Solution
{
public:
    vector<string> findRepeatedDnaSequences(string s)
    {
        // approach very simple create a sliding window of 10 size move it update map for frequency and print any sequence if the frequency is greater than 10
        int window_size = 10;
        int head = 0;
        int tail = head + window_size - 1;
        string window = "";
        for (int i = 0; i < window_size; i++)
        {
            window += s[i];
        }
        // now i have inital window time to initiate the map
        map<string, int> frequency_map;
        frequency_map[window] = 1;
        tail++;
        while (tail < s.size())
        {

            window += s[tail];
            window.erase(window.begin());
            //
            tail++;
            //
            if (frequency_map.count(window))
            {
                frequency_map[window]++;
            }
            else
            {
                frequency_map[window] = 1;
            }
        }
        // now i got the frequency map
        vector<string> ans;
        for (auto i = frequency_map.begin(); i != frequency_map.end(); i++)
        {
            if (i->second > 1)
            {
                ans.push_back(i->first);
            }
        }
        return ans;
    }
};