class Solution {
public:
    int ladderLength(string beginWord, string endWord, vector<string>& wordList) {
        queue<pair<string, int>>q;
        unordered_set<string>uset(wordList.begin(), wordList.end());

        uset.erase(beginWord);

        q.push({beginWord, 1});

        while(!q.empty()){
            auto it = q.front();
            q.pop();

            string str = it.first;
            int sz = it.second;

            if (str == endWord){
                return sz;
            }

            for(int i = 0; i < str.size(); i++){
                char org = str[i];
                for(char ch = 'a'; ch <= 'z'; ch++){
                    str[i] = ch;
                    if(uset.find(str) != uset.end()){
                        uset.erase(str);
                        q.push({str, sz + 1});
                    }
                }
                str[i] = org;
            }
        }
        return 0;
    }
};