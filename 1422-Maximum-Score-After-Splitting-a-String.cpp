class Solution {
public:
    int maxScore(string s) {
        int zeroes = 0, ones = 0;
        for(char c : s){
            if(c == '0') zeroes++;
            else ones++;
        }

        int zer1 = 0, one1 = ones, score = INT_MIN;
        for(int i = 0; i < s.size()-1; i++){
            if(s[i] == '0') zer1++;
            else one1--;

            score = max(score, zer1 + one1);
        }

        return score;
    }
};