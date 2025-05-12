class Solution 
{
public:
    vector<int> findEvenNumbers(vector<int>& digits) 
    {
        set<int> set;
        for (int i = 0; i < digits.size(); i++) 
        {
            for (int j = 0; j < digits.size(); j++) 
            {
                for (int k = 0; k < digits.size(); k++) 
                {
                    if (i == j || i == k || j == k)
                    {
                        continue;
                    }

                    int num = digits[i] * 100 + digits[j] * 10 + digits[k];

                    if (digits[i] != 0 && num % 2 == 0)
                    {
                        set.insert(num);
                    }
                }
            }
        }

        vector<int> result(set.begin(), set.end());
        return result;
    }
};