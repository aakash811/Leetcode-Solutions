class Solution {
public:
    vector<int> minOperations(string boxes) {
        int n = boxes.size();

        vector<int>vec;
        for(int i = 0; i < n; i++)
        {
            if(boxes[i] == '1')
            {
                vec.push_back(i);
            }
        }

        vector<int> res(n);
        for(int i = 0; i < n; i++)
        {
            int sum = 0;
            for(auto it : vec)
            {
                sum += abs(i - it);
            }
            res[i] = sum;
        }

        return res;
    }
};