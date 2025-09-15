class Solution {
public:
    int canBeTypedWords(string text, string broken){
        unordered_set<char> broSet;
        int cnt = 0;

        for (auto& c : broken){
            broSet.insert(c);
        }

        stringstream ss(text);
        string word;
        vector<string> words;

        while (ss >> word){
            words.push_back(word);
        }

        for (auto it : words)
        {
            for (char c : it)
            {
                if (broSet.find(c) != broSet.end())
                {
                    cnt++;
                    break;
                }
            }
        }

        return words.size() - cnt;
    }
};