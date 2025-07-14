class Solution {
public:
    vector<int> majorityElement(vector<int>& nums) {
        int n = nums.size();
        int major1 = 0;
        int major2 = 0;
        int cnt1 = 0;
        int cnt2 = 0;

        for(int i = 0; i < n; i++){
            if(nums[i] == major1){
                cnt1++;
            }
            else if(nums[i] == major2){
                cnt2++;
            }
            else if(cnt1 == 0){
                major1 = nums[i];
                cnt1++;
            }
            else if(cnt2 == 0){
                major2 = nums[i];
                cnt2++;
            }
            else{
                cnt1--;
                cnt2--;
            }
        }

        cnt1 = 0;
        cnt2 = 0;

        for(int i = 0; i < n; i++){
            if(nums[i] == major1){
                cnt1++;
            }
            else if(nums[i] == major2){
                cnt2++;
            }
        }

        vector<int>res;
        if(cnt1 > n / 3){
            res.push_back(major1);
        }
        if(cnt2 > n / 3){
            res.push_back(major2);
        }

        return res;
    }
};