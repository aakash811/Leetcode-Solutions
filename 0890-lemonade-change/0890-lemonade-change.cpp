class Solution {
public:
    bool lemonadeChange(vector<int>& bills) {
        int n = bills.size();
        int cnt = 0;
        vector<int>vec = {0, 0, 0};

        for(int i = 0; i < n; i++){
            int diff = bills[i] - 5;
            if(diff == 0){
                vec[0]++;
            }else if(diff == 5){
                if(vec[0] > 0){
                    vec[0]--;
                }
                else{
                    return false;
                }
                vec[1]++;
            }else if(diff == 15){
                if(vec[0] > 0 && vec[1] > 0){
                    vec[0]--;
                    vec[1]--;
                }
                else if(vec[0] > 2){
                    vec[0] -= 3;
                }
                else{
                    return false;
                }
                vec[2]++;
            }
        }

        return true;
    }
};