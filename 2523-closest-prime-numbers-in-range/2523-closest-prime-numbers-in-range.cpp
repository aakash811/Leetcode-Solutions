class Solution {
public:
    vector<bool> SieveOfEratosthenes(int n)
    {
        vector<bool> prime(n + 1, true);
        prime[0] = prime[1] = false;
        for (int p = 2; p * p <= n; p++) 
        {
            if (prime[p] == true) 
            {
                for (int i = p * p; i <= n; i += p)
                {
                    prime[i] = false;
                }
            }
        }

        return prime;
    }
    vector<int> closestPrimes(int left, int right) {
        vector<bool> vec = SieveOfEratosthenes(right);
        vector<int> primes;
        for(int i = left; i < vec.size(); i++)
        {
            if(vec[i] == true){
                primes.push_back(i);
            }
        }
        int mini = INT_MAX;
        int x = -1;
        int y = -1;

        if(primes.size() >= 2){
            for(int i = 0; i < primes.size() - 1; i++){
                if(mini > primes[i + 1] - primes[i])
                {
                    mini = primes[i + 1] - primes[i];
                    x = primes[i];
                    y = primes[i + 1];
                }
            }
        }else{
            return {-1, -1};
        }

        return {x, y};
    }
};