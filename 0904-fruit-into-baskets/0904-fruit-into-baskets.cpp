class Solution {
public:
    int totalFruit(vector<int>& fruits) {
        int n = fruits.size();
        unordered_map<int, int>ump;

        int left = 0;
        int right = 0;
        int maxLen = 0;

        while(right < n){
            ump[fruits[right]]++;

            while(ump.size() > 2){
                ump[fruits[left]]--;
                if(ump[fruits[left]] == 0){
                    ump.erase(fruits[left]);
                }
                left++;
            }
            maxLen = max(maxLen, right - left + 1);
            right++;
        }

        return maxLen;
    }
};