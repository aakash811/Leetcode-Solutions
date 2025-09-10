#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int minimumTeachings(int n, vector<vector<int>>& langs, vector<vector<int>>& friendships) {
        unordered_set<int> ump;

        for (auto& it : friendships) {
            int user1 = it[0] - 1;
            int user2 = it[1] - 1;
            bool canCommunicate = false;

            for (int lang1 : langs[user1]) {
                for (int lang2 : langs[user2]) {
                    if (lang1 == lang2) {
                        canCommunicate = true;
                        break;
                    }
                }
                if (canCommunicate) break;
            }

            if (!canCommunicate) {
                ump.insert(user1);
                ump.insert(user2);
            }
        }

        int minump = langs.size() + 1;

        for (int i = 1; i <= n; i++) {
            int count = 0;

            for (int user : ump) {
                bool knows = false;
                for (int lang : langs[user]) {
                    if (lang == i) {
                        knows = true;
                        break;
                    }
                }
                if (!knows) count++;
            }

            minump = min(minump, count);
        }

        return minump;
    }
};