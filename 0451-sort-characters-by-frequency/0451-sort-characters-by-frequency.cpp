class Solution {
public:
    static bool cmp(pair<char, int>& a, pair<char, int>& b) { 
        return a.second > b.second;
    } 
    
    string frequencySort(string s) {
        int n = s.size();
        map<char, int> mp;

        for (int i = 0; i < n; i++) {
            mp[s[i]]++;
        }

        vector<pair<char, int>> freq(mp.begin(), mp.end());

        sort(freq.begin(), freq.end(), cmp);

        string str = "";
        for (auto it : freq) {
            str.append(it.second, it.first); 
        }

        return str;
    }
};
