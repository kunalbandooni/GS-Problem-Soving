// https://leetcode.com/problems/valid-parentheses

class Solution {
public:
    bool isValid(string s) {
        stack<char> st;
        int i = 0, n = s.length();
        st.push(s[i++]);

        while(i < n) {
            if(s[i] == '{' || s[i] == '(' || s[i] == '[') {
                st.push(s[i]);
                i++;
                continue;
            }
            if(st.empty())  return false;
            if ((st.top() == '{' && s[i] == '}') || 
                (st.top() == '(' && s[i] == ')') || 
                (st.top() == '[' && s[i] == ']'))
                st.pop();
            else
                return false;
            i++;
        }

        return st.empty();
    }
};
