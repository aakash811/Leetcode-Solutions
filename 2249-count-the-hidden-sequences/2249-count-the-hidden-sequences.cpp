class Solution {
public:
    int numberOfArrays(vector<int>& diff, int lower, int upper) {
        int n = diff.size();
        long long int maxi = 0;
        long long int mini = 0;
        long long int sum = 0;

        for(int i = 0; i < n; i++){
            sum += diff[i];
            maxi = max(maxi, sum);
            mini = min(mini, sum);
        }

        return max(0LL, upper - lower - maxi + mini + 1);
    }
};