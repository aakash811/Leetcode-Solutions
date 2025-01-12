class Solution {
public:
    bool canBeValid(string s, string locked) {
        int n = s.size();
        
        if (n % 2 != 0) return false;

        stack<int> st; 
        stack<int> flexSt; 

        for (int i = 0; i < n; ++i) {
            if (locked[i] == '1') {
                if (s[i] == '(') {
                    st.push(i);
                } else { 
                    if (!st.empty()) {
                        st.pop(); 
                    } else if (!flexSt.empty()) {
                        flexSt.pop(); 
                    } else {
                        return false; 
                    }
                }
            } else {
                flexSt.push(i);
            }
        }

        while (!st.empty() && !flexSt.empty()) {
            if (st.top() > flexSt.top()) {
                return false; 
            }
            st.pop();
            flexSt.pop();
        }

        return st.empty();
    }
};
