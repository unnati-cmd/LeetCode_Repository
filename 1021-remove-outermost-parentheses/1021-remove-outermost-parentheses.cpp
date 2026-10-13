class Solution {
public:
    string removeOuterParentheses(string s) {
        stack<char> st;
        string str = "", v = "";
        for (char i : s) {
            if (i == '(') {
                st.push(i);
                str += i;
            }
            if (i == ')') {
                str += i;
                st.pop();
                if (st.empty()) {
                    v += str.substr(1, str.size() - 2);
                    str = "";
                }
            }
        }
        return v;
    }
};