class Solution {
public:
    bool isVowel(char ch){
        if(ch  == 'a' || ch == 'e' || ch == 'i' || ch == 'o' || ch == 'u'){
            return true;
        }
        return false;
    }

    int maxFreqSum(string s) {
        int n = s.size();
        unordered_map<char, int>ump;

        for(int i = 0; i < n; i++){
            ump[s[i]]++;
        }

        vector<pair<char, int>>vec (ump.begin(), ump.end());

        sort(vec.begin(), vec.end(), [](pair<char, int>& a, pair<char, int>& b){
            return a.second > b.second;
        });

        int res = 0;
        bool vow = false;
        bool cons = false;
        for(auto it : vec){
            if(isVowel(it.first) && !vow){
                vow = !vow;
                res += it.second;
            }
            else if(!isVowel(it.first) && !cons){
                cons = !cons;
                res += it.second;
            }
            if(vow && cons){
                break;
            }
        }

        return res;
    }
};