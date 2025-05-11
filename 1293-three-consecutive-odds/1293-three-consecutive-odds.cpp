class Solution {
public:
    bool threeConsecutiveOdds(vector<int>& arr) {
        int n = arr.size();

        for(int i = 0; i < n - 2; i++){
            bool flag = true;
            for(int j = 0; j < 3; j++){
                if(arr[i + j] % 2 != 0){
                    flag = true;
                }
                else{
                    flag = false;
                    break;
                }
            }
            if(flag){
                return true;
            }
        }
        return false;
    }
};