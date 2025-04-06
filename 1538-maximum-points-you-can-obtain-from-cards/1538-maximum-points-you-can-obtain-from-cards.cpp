class Solution {
public:
    int maxScore(vector<int>& cardPoints, int k) {
        int n = cardPoints.size();
        int winSz = n - k;
        int sum = 0;
        for(int i = 0; i < winSz; i++){
            sum += cardPoints[i];
        }

        int idx = 0;
        int winSum = sum;
        for(int i = winSz; i < n; i++){
            winSum += cardPoints[i] - cardPoints[i - winSz];
            if(sum > winSum){
                sum = winSum;
                idx = i;
            }
        }

        int totSum = 0;
        for(int i = 0; i < n; i++){
            totSum += cardPoints[i];
        }
        totSum -= sum;
        return totSum;
    }
};