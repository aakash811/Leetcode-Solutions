class Solution {
public:
    int fib(int n) {
        if(n == 0){
            return 0;
        }
        else if(n == 1){
            return 1;
        }
        else if(n == 2){
            return 1;
        }

        int prev1 = 1;
        int prev2 = 1;
        int curr = 0;
        for(int i = 3; i <= n; i++){
            curr = prev1 + prev2;
            prev2 = prev1;
            prev1 = curr;
        }

        return curr;
    }
};