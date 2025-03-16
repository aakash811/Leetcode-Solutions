class Solution {
public:
    bool solve(vector<int> &ranks, int cars, long long mid){
        long long carsCount = 0 ;
        for(long long i=0;i<ranks.size();i++){
            carsCount+= sqrt(mid/ranks[i]) ;
        }

        return carsCount>=cars ;

    }

    long long repairCars(vector<int>& ranks, int cars) {
        long long low = 0 , high = 1e18, ans =0  ;
        while(low<=high){
            long long mid = low + (high-low)/2 ;
            if(solve(ranks,cars,mid)){
                high = mid-1 ;
                ans = mid ;
            }
            else{
                low = mid+1 ;
            }

        }

        return ans ;

    }
};