class Solution {
public:
    string removeOuterParentheses(string s) {
       int n = s.size();
       stack<int>st;
       vector<int>ans;
       ans.push_back(0);
       int sum=0;
       for(int i=0;i<n;i++){
         if(s[i]=='('){
            sum++;
         }
         else{
            sum--;
         }
         
         if(sum==0){
            ans.push_back(i);
            if(i+1<n){
                ans.push_back(i+1);
            }
         }
       }
       
       string res="";
       int x=0;
       for(int i=0;i<n;i++){
          if(i==ans[x]){
            x++;
            continue;
          }
          else{
            res+=s[i];
          }
       }
       return res;   
    }
};