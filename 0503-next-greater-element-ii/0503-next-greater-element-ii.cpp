class Solution {
public:
    vector<int> nextGreaterElements(vector<int>& nums) {
        int n = nums.size();
        stack<int>stk;
        vector<int>res(n, -1);

        for(int i = 2 * n - 1; i >= 0; i--){
            while(!stk.empty() && nums[i % n] >= stk.top()){
                stk.pop();
            }

            if(i < n){
                if(!stk.empty()){
                    res[i] = stk.top();
                }
            }
            stk.push(nums[i % n]);
        }
        return res;
    }
};