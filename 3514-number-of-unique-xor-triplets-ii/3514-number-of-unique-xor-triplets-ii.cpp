class Solution {
public:
    int uniqueXorTriplets(vector<int>& nums) {
        int n = nums.size();
        unordered_set<int>uset;

        for(int i = 0; i < n; i++){
            uset.insert(nums[i]);
        }

        if(uset.size() < 3){
            return uset.size();
        }

        vector<int>vec(3000, 0);

        for(int i = 0; i < n; i++){
            for(int j = i + 1; j < n; j++){
                int xor1 = nums[i] ^ nums[j];
                vec[xor1] = 1;
            }
        }

        vector<int>res(3000, 0);
        for(int i = 0; i < n; i++){
            res[nums[i]] = 1;
            for(int j = 0; j < vec.size(); j++){
                if(vec[j] == 1){
                    int xor2 = j ^ nums[i];
                    res[xor2] = 1;
                }
            }
        }

        int uniqueXors = 0;
        for(int i = 0; i < res.size(); i++){
            if(res[i] == 1){
                uniqueXors++;
            }
        }

        return uniqueXors;
    }
};