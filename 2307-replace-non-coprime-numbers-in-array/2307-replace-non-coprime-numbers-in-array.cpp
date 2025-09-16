class Solution {
public:
    vector<int> replaceNonCoprimes(vector<int>& nums) {
        vector<int> res;
        
        for (int num : nums) {
            long long cur = num; 
            while (!res.empty()) {
                long long g = gcd(res.back(), cur);
                if (g == 1) break;  
                cur = (res.back() / g) * cur;  
                res.pop_back();
            }
            res.push_back((int)cur);
        }
        
        return res;
    }
    
    long long gcd(long long a, long long b) {
        return b == 0 ? a : gcd(b, a % b);
    }
};
