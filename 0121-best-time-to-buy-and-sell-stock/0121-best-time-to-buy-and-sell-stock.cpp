class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int n = prices.size();
        int buy = prices[0];
        int pro = 0;

        for(int i = 1; i < n; i++){
            if(buy > prices[i]){
                buy = prices[i];
            }
            pro = max(pro, prices[i] - buy);
        }

        return pro;
    }
};