class Solution {
public:
    bool divideArray(vector<int>& nums) {
        int n = nums.size();
        unordered_map<int,int>ump;
        int divs = n / 2;
        
        for(int i = 0; i < n; i++){
            ump[nums[i]]++;
        }

        if(ump.size() > divs){
            return false;
        }
        return true;
    }
};