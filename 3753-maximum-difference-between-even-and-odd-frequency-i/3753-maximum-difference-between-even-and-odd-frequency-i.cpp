class Solution {
public:
    int maxDifference(string s) {
        vector<int>freq(26, 0);

        for(int i = 0; i < s.size(); i++){
            freq[s[i] - 'a']++;
        }

        int maxOdd = 0;
        int minEven = INT_MAX;

        for(int i = 0; i < 26; i++){
            if(freq[i] % 2 == 0 && freq[i] != 0){
                minEven = min(minEven, freq[i]);
            }
            else{
                maxOdd = max(maxOdd, freq[i]);
            }
        }
        // cout<<maxOdd<<" "<<minEven<<" ";

        return maxOdd - minEven;
    }
};