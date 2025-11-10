class Solution {
public:
    int minOperations(vector<int>& nums) {
        nums.push_back(0);
        vector<int>stack;
        int cnt = 0;

        for(int i = 0; i < nums.size(); i++){
            while(!stack.empty()){
                if(nums[i] > stack.back()){
                    stack.push_back(nums[i]);
                    break;
                }
                else if(nums[i] < stack.back()){
                    stack.pop_back();
                    cnt++;
                }
                else{
                    break;
                }
            }
            
            if(stack.empty() && nums[i] != 0){
                stack.push_back(nums[i]);
            }
        }
        return cnt;
    }
};