class Solution {
public:
    int minimumPushes(string word) {
        int n = word.size();
        vector<int>vec(26);

        for(int i = 0; i < n; i++){
            vec[word[i] - 'a']++;
        }

        sort(vec.rbegin(), vec.rend());

        int cnt = 8;
        int taps = 1;
        int res = 0;

        for(int i = 0; i < 26; i++){
            if(vec[i] > 0 && cnt > 0){
                res += taps;
                cnt--;
            }
            if(cnt == 0){
                cnt = 8;
                taps += 1;
            }
        }

        return res;
    }
};