class Solution {
public:
    int minimumPushes(string word) {
        int n = word.size();
        vector<int>vec(26, 0);

        for(int i = 0; i < n; i++){
            vec[word[i] - 'a']++;
        }
        sort(vec.rbegin(), vec.rend());
        int cnt = 0;
        int taps = 1;
        int res = 0;

        for(int i = 0; i < 26; i++){
            cnt++; 
            res += (taps * vec[i]);
            if(cnt == 8){
                cnt = 0;
                taps += 1;
            }
        }

        return res;
    }
};