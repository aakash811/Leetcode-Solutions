class Solution 
{
public:
    string clearStars(string s) 
    {
        int n = s.size();
        vector<bool> rem(n, false);
        vector<vector<int>> idxs(26);
        for (int i = 0; i < n; ++i) 
        {
            if (s[i] == '*') 
            {
                rem[i] = true;
                for (int j = 0; j < 26; ++j) 
                {
                    if (!idxs[j].empty()) 
                    {
                        int idx = idxs[j].back();
                        idxs[j].pop_back();
                        rem[idx] = true;
                        break;
                    }
                }
            } 
            else 
            {
                idxs[s[i] - 'a'].push_back(i);
            }
        }

        string res;
        for (int i = 0; i < n; ++i) 
        {
            if (!rem[i] && s[i] != '*') 
            {
                res += s[i];
            }
        }

        return res;
    }
};