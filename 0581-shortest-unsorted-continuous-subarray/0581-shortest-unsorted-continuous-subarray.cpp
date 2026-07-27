class Solution {
public:
    int findUnsortedSubarray(vector<int>& nums) {
        int n = nums.size();

        int i = 0;
        bool flag = false;
        while(i < n - 1){
            if(i > 0 && nums[i] == nums[i - 1]){
                i++;
                continue;
            }
            int j = i + 1;
            while(j < n){
                if(j >= i + 1 && nums[j] == nums[j - 1]){
                    j++;
                    continue;
                }
                if(j < n && nums[i] <= nums[j]){
                    j++;
                }
                else{
                    flag = true;
                    break;
                }
            }
            if(flag){
                break;
            }
            i++;
        }

        int k = n - 1 ;
        bool flag1 = false;
        while(k >= 0){
            if(k < n - 1 && nums[k] == nums[k + 1]){
                k--;
                continue;
            }
            int l = k - 1;
            while(l >= 0){
                if(l >= k - 1 && nums[l] == nums[l + 1]){
                    l--;
                    continue;
                }
                if(l >= 0 && nums[k] >= nums[l]){
                    l--;
                }
                else{
                    flag1 = true;
                    break;
                }
            }
            if(flag1){
                break;
            }
            k--;
        }

        return (flag && flag1) ? k - i + 1 : 0;
    }
};