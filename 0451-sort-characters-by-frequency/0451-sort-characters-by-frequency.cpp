class Solution {
public:
    string frequencySort(string s) {
        int n = s.size();
        unordered_map<char, int>ump;
        for(int i = 0; i < n; i++){
            ump[s[i]]++;
        }
        
        vector<pair<char, int>>v(ump.begin(), ump.end());
        
        sort(v.begin(), v.end(), [](auto a, auto b){
            return a.second > b.second;
        });
        
        int idx = 0;
        for(int i = 0; i < v.size(); i++){
            int freq = v[i].second;
            for(int x = 0; x < freq; x++){
                s[idx] = v[i].first;
                idx++;
            }
        }
        
        return s;
    }
};