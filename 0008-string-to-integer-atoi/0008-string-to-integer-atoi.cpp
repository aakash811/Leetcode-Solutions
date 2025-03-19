class Solution {
public:
    int solve(string s, int i, int sign, long ans){
        if(i >= s.size() || !isdigit(s[i])){
            return ans * sign;
        }

        ans = ans * 10 + (s[i] - '0');
        if(sign * ans < INT_MIN){
            return INT_MIN;
        }
        if(sign * ans > INT_MAX){
            return INT_MAX;
        }

        return solve(s, i + 1, sign, ans);
    }
    int myAtoi(string s) 
    {
        int i=0;
        int sign=1;
        long ans=0;
        while(i<s.length() && s[i]==' ')
            i++;
        if(s[i]=='-')
        {
            sign=-1;
            i++;
        }
        else if(s[i]=='+')
            i++;
        return solve(s, i, sign, ans);
    }
};