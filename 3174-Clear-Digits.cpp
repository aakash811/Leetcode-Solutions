class Solution {
public:
    string clearDigits(string s) {
        int n = s.size();
        stack<char>stk;
        stk.push(s[0]);

        for(int i = 1; i < n; i++)
        {
            if(!isdigit(s[i]))
            {
                stk.push(s[i]);
            }
            else
            {
                stk.pop();
            }
        }

        string str = "";
        while(!stk.empty())
        {
            str += stk.top();
            stk.pop();
        }

        reverse(str.begin(), str.end());
        return str;
        // while()
    }
};