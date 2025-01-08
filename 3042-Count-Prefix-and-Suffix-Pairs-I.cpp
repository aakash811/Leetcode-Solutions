class Solution {
public:
    bool isPrefixAndSuffix(string s1, string s2)
    {
        for(int i = 0; i < s1.size(); i++)
        {
            if(s1[i] != s2[i])
            {
                return false;
            }
        }
        reverse(s1.begin(), s1.end());
        reverse(s2.begin(), s2.end());

        for(int i = 0; i < s1.size(); i++)
        {
            if(s1[i] != s2[i])
            {
                return false;
            }
        }
        return true;
    }

    int countPrefixSuffixPairs(vector<string>& words) {
        int n = words.size();
        int cnt = 0;
        for(int i = 0; i < n; i++)
        {
            for(int j = i + 1; j < n; j++)
            {
                if(isPrefixAndSuffix(words[i], words[j]))
                {
                    cnt++;
                }
            }
        }
        return cnt;
    }
};