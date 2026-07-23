class Solution {
public:
    int uniqueXorTriplets(vector<int>& nums) {
        int n = nums.size();
        if(n < 3){
            return n;
        }
        else{
            int bins = log2(n) + 1;
            cout<<bins;

            int res = pow(2, bins);
            return res;
        }
    }
};