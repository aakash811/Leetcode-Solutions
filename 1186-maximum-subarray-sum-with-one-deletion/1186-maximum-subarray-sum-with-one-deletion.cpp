class Solution {
public:
    int maximumSum(vector<int>& arr) {
        int n = arr.size();

        int maxNoDel = arr[0];
        int maxOneDel = arr[0];
        int maxSum = arr[0];

        for(int i = 1; i < n; i++){
            int prevNoDel = maxNoDel;

            maxNoDel = max(maxNoDel + arr[i], arr[i]);
            maxOneDel = max(maxOneDel + arr[i], prevNoDel);

            maxSum = max({maxSum, maxNoDel, maxOneDel});
        }

        return maxSum;
    }
};