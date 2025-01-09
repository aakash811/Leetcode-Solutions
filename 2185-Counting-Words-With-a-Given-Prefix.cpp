class Solution {
public:
    int prefixCount(vector<string>& words, string pref) {
        int n = words.size();
        int sz = pref.size();
        int cnt = 0;
        for(int i = 0; i < n; i++)
        {
            bool flag = true;
            for(int j = 0; j < sz; j++)
            {
                if(pref[j] != words[i][j])
                {
                    flag = false;
                    break;
                }
            }
            if(flag)
            {
                cnt++;
            }
        }
        return cnt;
    }
};