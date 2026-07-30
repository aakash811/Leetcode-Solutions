class Solution {
public:
    int totalFruit(vector<int>& fruits) {
        int n = fruits.size();

        int left = 0;
        int right = 0;

        int type1 = -1;
        int type2 = -1;

        int idx1 = -1;
        int idx2 = -1;

        int maxLen = 0;

        while(right < n){
            if(fruits[right] == type1){
                idx1 = right;
            }
            else if(fruits[right] == type2){
                idx2 = right;
            }
            else{
                if(type1 == -1){
                    type1 = fruits[right];
                    idx1 = right;
                }
                else if(type2 == -1){
                    type2 = fruits[right];
                    idx2 = right;
                }
                else{
                    if(idx1 < idx2){
                        left = idx1 + 1;
                        type1 = fruits[right];
                        idx1 = right;
                    }
                    else{
                        left = idx2 + 1;
                        type2 = fruits[right];
                        idx2 = right;
                    }
                }
            }
            maxLen = max(maxLen, right - left + 1);
            right++;
        }

        return maxLen;
    }
};