class Solution {
public:
    bool isAnagram(string s, string t) {
       int n = s.size();
       int m = t.size();

       if(n != m){
        return false;
       } 

      vector<int>hshMap1(256, 0);
      vector<int>hshMap2(256, 0);

       for(int i = 0; i < n; i++){
            hshMap1[s[i]]++;
            hshMap2[t[i]]++; 
       }

       for(int i = 0; i < hshMap1.size(); i++){
            if(hshMap1[i] != hshMap2[i]){
                return false;
            }
       }

    //    for(auto it : hshMap1){
    //     cout<<it<<" ";
    //    }
    //    cout<<endl;
    //    for(auto it : hshMap2){
    //     cout<<it<<" ";
    //    }
       return true;
    }
};