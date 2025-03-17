class Solution {
public:
    bool divideArray(vector<int>& nums) {
        int n = nums.size();
        unordered_map<int,int>ump;
        int divs = n / 2;
        
        // cout<<n<<" "<<divs<<endl;
        for(int i = 0; i < n; i++){
            ump[nums[i]]++;
        }
        // cout<<ump.size()<<endl;
        int pairs = 0;
        for(auto it : ump){
            pairs += (it.second + 1) / 2;
        }

        if(pairs != divs){
            return false;
        }
        return true;
    }
};