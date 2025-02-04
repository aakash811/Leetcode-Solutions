class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
      unordered_set<int>uset;
      int lcs = 1;
      if (nums.size() == 0) return 0;
      for(int i = 0; i < nums.size(); i++)
      {
        uset.insert(nums[i]);
      }  

      for(int it : uset)
      {
        if(uset.find(it - 1) == uset.end())
        {
            int cnt = 1;
            int x = it;

            while (uset.find(x + 1) != uset.end()) 
            {
                x = x + 1;
                cnt = cnt + 1;  
            }

            lcs = max(cnt, lcs);
        }
      }
      return lcs;
    }
};