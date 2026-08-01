class Solution {
public:
    bool matches(vector<int>& freqS, vector<int>& freqP){
        for(int i = 0; i < 26; i++){
            if(freqS[i] != freqP[i]){
                return false;
            }
        }
        return true;
    }

    vector<int> findAnagrams(string s, string p) {
        int n = s.size();
        int m = p.size();

        if(n < m){
            return {};
        }

        vector<int>freqS(26, 0);
        vector<int>freqP(26, 0);
        vector<int>starts;

        for(int i = 0; i < m; i++){
            freqS[s[i] - 'a']++;
            freqP[p[i] - 'a']++;
        }
        if(matches(freqS, freqP)){
            starts.push_back(0);
        }

        for(int i = m; i < n; i++){
            freqS[s[i] - 'a']++;
            freqS[s[i - m] - 'a']--;

            if(matches(freqS, freqP)){
                starts.push_back(i - m + 1);
            }
        }

        return starts;
    }
};