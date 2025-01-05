class Solution {
public:
    string shiftingLetters(string s, vector<vector<int>>& shifts) {
        int n = s.size();
        vector<int> vec(n + 1, 0); 
        
        for (auto& shift : shifts) {
            int start = shift[0];
            int end = shift[1];
            int direction = (shift[2] == 1) ? 1 : -1;

            vec[start] += direction;
            vec[end + 1] -= direction; 
        }

        int shft = 0;
        for (int i = 0; i < n; i++) {
            shft += vec[i];
            int chrShft = (shft % 26 + 26) % 26;
            s[i] = 'a' + (s[i] - 'a' + chrShft) % 26;
        }

        return s;
    }
};
