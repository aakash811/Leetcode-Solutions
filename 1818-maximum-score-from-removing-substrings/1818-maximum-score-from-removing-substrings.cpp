class Solution {
public:
    int solve(string &s, char fst, char sec, int x, int y){
        int score = 0;
        vector<char>stk;

        for(char c : s){
            if(!stk.empty() && stk.back() == fst && c == sec){
                stk.pop_back();
                score += x;
            }
            else{
                stk.push_back(c);
            }
        }

        vector<char>stk1;
        for(auto ch : stk){
            if(!stk1.empty() && stk1.back() == sec && ch == fst){
                stk1.pop_back();
                score += y;
            }
            else{
                stk1.push_back(ch);
            }
        }
        return score;
    }

    int maximumGain(string s, int x, int y) {
        if(x < y){
            return solve(s, 'b', 'a', y, x);
        }
        else{
            return solve(s, 'a', 'b', x, y);
        }
    }
};