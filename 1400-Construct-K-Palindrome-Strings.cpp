class Solution {
public:
    bool canConstruct(string s, int k) {
        unordered_map<char,int>ump;
        for(int i = 0; i < s.size(); i++)
        {
            ump[s[i]]++;
        }
        int evenFreq = 0;
        int oddFreq = 0;

        for(auto it : ump)
        {
            if(it.second % 2 == 0)
            {
                evenFreq++;
            }
            else
            {
                oddFreq++;
            }
        }
        if(s.size() >= k)
        {
            if(oddFreq <= k)
            {
                return true;
            }
            else if(oddFreq > k || evenFreq + 1 < k)
            {
                return false;
            }
        }
        return false;

    }
};