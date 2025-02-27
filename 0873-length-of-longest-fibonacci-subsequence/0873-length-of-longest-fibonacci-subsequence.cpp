class Solution {
public:
    int lenLongestFibSubseq(vector<int>& arr) {
        int n = arr.size();

        if(n < 2){
            return 0;
        }

        unordered_map<int,int>ump;

        for(int i = 0; i < n; i++){
            ump[arr[i]]++;
        }

        int maxLen = 0;
        for(int i = 0; i < n; i++)
        {
            for(int j = i + 1; j < n; j++)
            {
                int prev1 = arr[j];
                int prev2 = arr[i];

                int len = 2;

                while(ump.find(prev1 + prev2) != ump.end()){
                    len++;
                    maxLen = max(maxLen, len);
                    int x = prev1;
                    prev1 += prev2;
                    prev2 = x;
                }
            }
        }

        return maxLen > 2 ? maxLen : 0;
    }
};