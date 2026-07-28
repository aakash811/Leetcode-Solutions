class Solution {
public:
    string smallestPalindrome(string s) {
        int n = s.size();
        map<char, int>ump;

        for(int i = 0; i < n; i++){
            ump[s[i]]++;
        }

        string first = "";
        char mid = '0';
        cout<<"mid1 -> "<<mid<<endl;
        string second = "";
        for(auto it: ump){
           if(it.second % 2 == 0){
                int times = it.second / 2;
                while(times--){
                    first += it.first;
                    second += it.first;
                }
           }
           else{
                int times = it.second / 2;
                while(times--){
                    first += it.first;
                    second += it.first;
                }
                mid = it.first;
            cout<<"mid2 -> "<<mid<<endl;
           }
        }
        cout<<"mid3 -> "<<mid<<endl;

        reverse(second.begin(), second.end());

        return (mid != '0') ? first + mid + second : first + second;
    }
};