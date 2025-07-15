class Solution {
public:
    bool isVowel(char c) {
        c = tolower(c);
        return c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u';
    }

    bool hasVowel(const string& word) {
        for (char c : word) {
            if (isalpha(c) && isVowel(c)) return true;
        }
        return false;
    }

    bool hasConsonant(const string& word) {
        for (char c : word) {
            if (isalpha(c) && !isVowel(c)) return true;
        }
        return false;
    }

    bool isValid(const string& word) {
        if (word.size() < 3) return false;

        for (char c : word) {
            if (!isalnum(c)) return false;
        }

        return hasVowel(word) && hasConsonant(word);
    }
};
