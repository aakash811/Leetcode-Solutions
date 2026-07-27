class Solution {
public:
    int squareDigits(int n){
        int res = 0;
        while(n > 0){
            int digit = n % 10;
            n /= 10;
            res += digit * digit;
        }

        return res;
    }

    bool isHappy(int n) {
        int slow = n;
        int fast = n;

        while(true){
            slow = squareDigits(slow);
            fast = squareDigits(squareDigits(fast));

            if(fast == 1){
                return true;
            }

            if(fast == slow){
                return false;
            }
        }

        return false;
    }
};