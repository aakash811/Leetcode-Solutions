class Solution {
public:
    string toLower(string s) {
        for (char &c : s) {
            c = tolower(c);
        }
        return s;
    }

    string solve(string s) {
        for (char &c : s) {
            if (isVowel(c)){
                c = '*';
            }
        }
        return s;
    }

    bool isVowel(char c) {
        c = tolower(c);
        return c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u';
    }

    vector<string> spellchecker(vector<string>& wordlist, vector<string>& queries) {
        unordered_set<string> dict(wordlist.begin(), wordlist.end());
        unordered_map<string, string> caseMap;
        unordered_map<string, string> vowMap;

        for (string it : wordlist) {
            string lower = toLower(it);
            string noVow = solve(lower);
            if (!caseMap.count(lower)) caseMap[lower] = it;
            if (!vowMap.count(noVow)) vowMap[noVow] = it;
        }
        vector<string> res;
        for (string q : queries) {
            if (dict.count(q)) {
                res.push_back(q);
            } else {
                string lower = toLower(q);
                string noVow = solve(lower);

                if (caseMap.count(lower)) res.push_back(caseMap[lower]);
                else if (vowMap.count(noVow)) res.push_back(vowMap[noVow]);
                else res.push_back("");
            }
        }
        return res;
    }
};