class Solution {
public:
    bool lemonadeChange(vector<int>& bills) {
        vector<int>vec = {0, 0, 0};
        int n = bills.size();
        if(bills[0] == 10 || bills[0] == 20){
            return false;
        }

        for(int i = 0; i < n; i++){
            if(bills[i] == 5){
                vec[0]++;
            }

            if(bills[i] == 10){
                vec[1]++;
                if(vec[0] > 0){
                    vec[0]--;
                }
                else{
                    return false;
                }
            }

            
            if(bills[i] == 20){
                vec[2]++;
                if((vec[0] > 0 && vec[1] > 0)){
                    vec[0]--;
                    vec[1]--;
                }
                else if(vec[0] >= 3){
                    vec[0] -= 3;
                }
                else{
                    return false;
                }
            }
        }
        return true;
    }
};