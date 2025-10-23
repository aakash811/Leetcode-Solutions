class Solution {
public:
    bool hasSameDigits(string s) {
        int n = s.size();

        while(s.length() > 2)
        {
            vector<char> temp;
            for (int i = 0; i < s.length() - 1; i++) {
                int sum = ((s[i] - '0') + (s[i + 1] - '0')) % 10;
                temp.push_back(sum + '0');
            }
            s = string(temp.begin(), temp.end()); 
        }
        return s[0] == s[1];
    }
};