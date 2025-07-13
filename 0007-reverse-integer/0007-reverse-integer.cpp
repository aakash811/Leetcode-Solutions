class Solution {
public:
    int reverse(long long x) {
        long long  rev = 0;
        long long temp = x;

        bool flag = false;
        if(x < 0)
        {
            flag = true;
            x *= -1;
        }
        while(x > 0)
        {
            rev = (rev * 10) + (x % 10);
            x /= 10;
        }

        if(rev > ((pow(2,31) - 1)))
        {
            return 0;
        }
        else if(rev < (pow(2,31) * -1))
        {
            return 0;
        }
        else
        {
            if(flag)
            {
                return rev*-1;
            }
            return rev;
        }
        return 0;
    }
};