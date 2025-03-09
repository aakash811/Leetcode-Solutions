class Solution {
public:
    int numberOfAlternatingGroups(vector<int>& colors, int k) {
        colors.insert(colors.end(), colors.begin(), colors.begin() + (k - 1));
        int res = 0;
        int idx = 0;

        cout<<endl;
        for(int i = 0; i < colors.size(); i++)
        {
            if(i > 0 && colors[i] == colors[i - 1])
            {
                idx = i;        
            }

            if(i - idx + 1 >= k)
            {
                res++;
            }
        }
        return res;
    }
};