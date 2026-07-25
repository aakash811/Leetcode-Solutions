class Solution {
public:
    int maxProduct(int n) {
        vector<int>digits;
        while(n > 0){
            digits.push_back(n % 10);
            n /= 10;
        }

        sort(digits.begin(), digits.end());
        int dig1 = digits.back();
        digits.pop_back();
        int dig2 = digits.back();
        return dig1 * dig2;
    }
};