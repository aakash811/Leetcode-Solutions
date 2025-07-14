class Solution {
public:
    int myAtoi(string s) {
        int n = s.size();
        
        int idx = 0;
        while(s[idx] == ' '){
            idx++;
        }
        bool flag = true;
        if(s[idx] == '-' || s[idx]=='+'){
            
          if(s[idx]=='-'){
            flag=false;
          }
            idx++;
        }
       
        long long num = 0;
        for(int i = idx; i < n; i++){
            if(isdigit(s[i])){
                num *= 10;
                num += s[i] - '0';
            }else{
                break;
            }

            if(flag && num > INT_MAX){
                return INT_MAX;
            }
            if( !flag && -1*num < INT_MIN){
                return INT_MIN;
            }
        }
        
        if(!flag){
            num *= -1;
        }
      
        return num;
        
    }
};