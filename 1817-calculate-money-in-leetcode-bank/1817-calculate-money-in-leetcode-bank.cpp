class Solution {
public:
    int totalMoney(int n) {
        int x = 0;
        int weeks = n / 7;

        while (n != 0)
        {
            if (n >= 7)
            {
                x = 28;
                for(int i = weeks ; i > 1 ; i--)
                {
                    if(weeks > 1)
                    {
                        x += 28 + ((i - 1) * 7);
                    }
                }

                n -= (weeks * 7);
            }
            else
            {
                for (int i = weeks + 1; n != 0; i++)
                {
                    x += i;
                    n--;
                }
            }
        }
        return x;
    }
};