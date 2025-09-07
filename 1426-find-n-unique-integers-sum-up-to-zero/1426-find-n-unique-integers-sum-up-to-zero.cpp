class Solution {
public:
    vector<int> sumZero(int n) {
        vector<int>res;
        int ele = 1;
        while(n){
            if(n % 2 == 0){
                res.push_back(ele);
                res.push_back(-1 * ele);
                n -= 2;
                ele++;
            }
            else{
                res.push_back(0);
                n--;
            }
        }

        return res;
    }
};