class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int n = prices.size();
        int buy = prices[0];
        int pro = 0;

        for(int i = 1; i < n; i++){
            if(prices[i] < buy){
                buy = prices[i];
            }

            int x = prices[i] - buy;
            pro = max(pro, x);
        }

        return pro;
    }
};