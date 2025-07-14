class Solution {
public:
bool isPalin(string &s){
    int i=0;
    int j=s.length()-1;
    
    while(i<j){
        if(s[i]!=s[j]){
            return false;
        }
        i++;
        j--;
    } 
    return true;
}

   

    string longestPalindrome(string s) {
        int n=s.length();
        string maxi="";
        
        for(int i=0;i<n;i++){
            string temp="";
            for(int j=i;j<n;j++){
                temp+=s[j];
                if(isPalin(temp)){
                    if(temp.length()>maxi.length()){
                        maxi=temp;
                    }
                }
            }
        }
        
        return maxi;
    }
};