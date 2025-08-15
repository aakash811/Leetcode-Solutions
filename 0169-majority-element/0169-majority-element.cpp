class Solution {
public:
    int majorityElement(vector<int>& nums) {
        int n = nums.size();
        int cnt = 0;
        int majorElement;

        for(int i = 0; i < n; i++){
            if(cnt == 0){
                majorElement = nums[i];
                cnt = 1;
            }
            else if(nums[i] == majorElement){
                cnt++;
            }
            else if(nums[i] != majorElement){
                cnt--;
            }
        }
        
        cnt = 0;
        for(int i = 0; i < n; i++){
            if(nums[i] == majorElement){
                cnt++;
            }
        }

        if(cnt > (n / 2)){
            return majorElement;
        }
        return -1;
    }
};