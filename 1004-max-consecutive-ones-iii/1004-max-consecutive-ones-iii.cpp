class Solution {
public:
    int longestOnes(vector<int>& nums, int k) {
        int n = nums.size();
        int left = 0;
        int right = 0;
        int maxLen = 0;

        int ones = 0;
        int zeroes = 0;

        while(right < n){
            if(nums[right] == 1){
                ones++;
            }
            else{
                zeroes++;
                while(zeroes > k){
                    if(nums[left] == 1){
                        ones--;
                    }
                    else if(nums[left] == 0){
                        zeroes--;
                    }
                    left++;
                }
                cout<<"zeroes-> "<<zeroes<<" ";
                cout<<"ones-> "<<ones<<endl;
            }
            maxLen = max(maxLen, right - left + 1);
            cout<<"maxLen-> "<<maxLen<<endl;
            right++;
        }
        
        return maxLen;
    }
};