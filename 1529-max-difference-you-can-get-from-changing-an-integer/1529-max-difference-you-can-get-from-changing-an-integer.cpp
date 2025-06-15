class Solution {
public:
    int maxDiff(int num) {
        string str = to_string(num);
        string mini = str;
        string maxi = str;

        char x1 = 0;
        for (int i = 0; i < str.size(); i++) {
            if (str[i] != '9') {
                x1 = str[i];
                break;
            }
        }

        if (x1 != 0) {
            for (int i = 0; i < str.size(); i++) {
                if (maxi[i] == x1) {
                    maxi[i] = '9';
                }
            }
        }

        char x2 = 0;

        if (str[0] != '1') {
            x2 = str[0];
            for (int i = 0; i < str.size(); i++) {
                if (mini[i] == x2) {
                    mini[i] = '1';
                }
            }
        } else {
            for (int i = 1; i < str.size(); i++) {
                if (str[i] != '0' && str[i] != '1') {
                    x2 = str[i];
                    break;
                }
            }

            if (x2 != 0) {
                for (int i = 0; i < str.size(); i++) {
                    if (mini[i] == x2) {
                        mini[i] = '0';
                    }
                }
            }
        }

        int maxNum = stoi(maxi);
        int minNum = stoi(mini);
        return maxNum - minNum;
    }
};
