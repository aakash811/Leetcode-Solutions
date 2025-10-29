class Solution {
public:
    vector<int>res = {1, 3, 7, 15, 31, 63, 127, 255, 511, 1023};
    int smallestNumber(int n) {
        for(int i = 0; i < res.size(); i++){
            if(n <= res[i]){
                return res[i];
            }
            else{
                continue;
            }
        }

        return -1;
    }
};