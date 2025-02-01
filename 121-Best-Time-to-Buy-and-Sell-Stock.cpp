class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int n = prices.size();
        int buy = prices[0];
        int maxProf = 0;
        for(int i = 1; i < n; i++)
        {
            if(buy > prices[i])
            {
                buy = prices[i];
            }
            maxProf = max(maxProf, prices[i] - buy);
        }
        return maxProf;
    }
};