class Solution {
public:
    bool solve(vector<int>& candies, long long int mid, long long int k){
        long long int n = candies.size();
        long long int cnt = 0;

        for(auto it : candies){
            cnt += (it/mid);
        }
        return cnt >= k;
    }

    int maximumCandies(vector<int>& candies, long long k) {
        long long int n = candies.size();
        long long int lo = 1;
        long long int hi = *max_element(candies.begin(), candies.end());

        while(lo <= hi){
            long long int mid = (lo + hi) >> 1;
            if(solve(candies, mid, k)){
               lo = mid + 1; 
            }
            else{
                hi = mid - 1;
            }
        }
        return hi;
    }
};