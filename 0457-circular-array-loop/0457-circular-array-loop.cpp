class Solution {
public:
    int nextIdx(int i, vector<int>& nums){
        int n = nums.size();
        return ((i + nums[i]) % n + n) % n;
    }

    bool isSameDirn(int i, int idx, vector<int>& nums){
       return nums[idx] > 0 == nums[i] > 0;
    }

    bool circularArrayLoop(vector<int>& nums) {
        int m = nums.size();

        for(int i = 0; i < m; i++){
            if(nums[i] == 0){
                continue;
            }

            int slow = i;
            int fast = i;

            while(true){
                if(!isSameDirn(i, slow, nums) || !isSameDirn(i, fast, nums)){
                    break;
                }
                int nextFast = nextIdx(fast, nums);

                if(!isSameDirn(i, nextFast, nums)){
                    break;
                }

                slow = nextIdx(slow, nums);
                fast = nextIdx(nextFast, nums);

                if(slow == fast){
                    if(slow == nextIdx(slow, nums)){
                        break;
                    }
                    return true;
                }
            }

            int curr = i;
            while(nums[curr] != 0 && isSameDirn(i, curr, nums)){
                int nextCurr = nextIdx(curr, nums);
                nums[curr] = 0;
                curr = nextCurr;
            }
        }  

        return false;  
    }
};