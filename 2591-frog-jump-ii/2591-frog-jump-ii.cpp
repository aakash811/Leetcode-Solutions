class Solution {
public:
    int maxJump(vector<int>& stones) {
        int maxJmp = 0;
        int n = stones.size();

        if(n < 3){
            return stones[1] - stones[0];
        }
        for(int i = 2; i < n; i++){
            maxJmp = max(maxJmp, stones[i] - stones[i - 2]);
        }
        for(int i = 3; i < n; i++){
            maxJmp = max(maxJmp, stones[i] - stones[i - 2]);
        }
        return maxJmp;
    }
};