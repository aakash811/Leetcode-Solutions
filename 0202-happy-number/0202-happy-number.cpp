class Solution {
public:
    int squaringDigits(int n){
        vector<int>digs;
        while(n != 0){
            digs.push_back(n % 10);
            n /= 10;
        }

        int sqr = 0;
        for(int i = 0; i < digs.size(); i++){
            sqr += digs[i] * digs[i];
        }
        return sqr;
    }

    bool isHappy(int n) {
        int slow = n;
        int fast = n;

        while(true){
            slow = squaringDigits(slow);
            fast = squaringDigits(squaringDigits(fast));

            if(fast == 1){
                return true;
            }
            
            if(fast == slow){
                break;
            }
        }

        return false;
    }
};