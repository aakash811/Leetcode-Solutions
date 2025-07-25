class Solution {
public:
    vector<int> asteroidCollision(vector<int>& asteroids) {
        int n = asteroids.size();
        stack<int>stk;
        vector<int>res;

        for(int i = 0; i < n; i++){
            if(stk.empty()){
                stk.push(asteroids[i]);
            } 
            else if(asteroids[i] > 0){
                stk.push(asteroids[i]);
            }
            else if(asteroids[i] < 0){
                while(!stk.empty() && stk.top() > 0 && stk.top() < abs(asteroids[i])){
                    stk.pop();
                }
                if(!stk.empty() && stk.top() > 0){
                    if(stk.top() == abs(asteroids[i])){
                        stk.pop();
                    }
                }
                else{
                    stk.push(asteroids[i]);
                }
            }
        }
        
        while(!stk.empty()){
            res.push_back(stk.top());
            stk.pop();
        }
        reverse(res.begin(), res.end());
        return res;
    }
};