class Solution {
public:
    int findKthPositive(vector<int>& arr, int k) {
        int n = arr.size();
        int lo = 0, hi = n - 1;
        while(lo <= hi){
            int mid = lo + (hi - lo) / 2;
            int diff = arr[mid] - mid - 1;

            if(diff < k){
                lo = mid + 1;
            }
            else{
                hi = mid - 1;
            }
        }
        return lo + k;
    }
};