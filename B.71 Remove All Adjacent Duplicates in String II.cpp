// https://leetcode.com/problems/remove-all-adjacent-duplicates-in-string-ii

class Solution {
    string giveString(int n, char ch) {
        string s = "";
        while(n--)
            s += ch;
        return s;
    }
public:
    string removeDuplicates(string s, int k) {
        vector<pair<char, int>> st;
        string res;
        for (auto ch : s) {
            if (st.empty() || st.back().first != ch)
                st.push_back({ch, 0 });
            st.back().second++;
            if (st.back().second == k)
                st.pop_back();
        }
        for (auto& p : st) 
            res += giveString(p.second, p.first);
        return res;
    }
};
