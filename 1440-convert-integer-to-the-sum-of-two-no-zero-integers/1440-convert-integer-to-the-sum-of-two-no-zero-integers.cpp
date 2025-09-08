class Solution {
public:
    bool solve(int a){
        while(a){
            int dig = a % 10;
            if(dig == 0){
                return false;
            }
            a /= 10;
        }    
        return true;
    }

    vector<int> getNoZeroIntegers(int n) {       
        for(int i = 1; i < n; i++){
            int a = i;
            int b = n - i;

            if(solve(a) && solve(b)){
                return {a, b};
            }
        }
        return {};
    }
};