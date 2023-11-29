// https://leetcode.com/problems/decode-ways/

class Solution {
    int f(string s, int i, vector<int> &dp) {
        if(i >= s.size()) return 1;
        if(s[i] == '0') return 0;
        if(dp[i] != -1) return dp[i];
        
        int res = f(s, i+1, dp);
        if(i+1 < s.size() && (s[i] == '1' || s[i] == '2' && s[i+1] <= '6'))
            res += f(s, i+2, dp);

        return dp[i] = res;
    }
public:
    int numDecodings(string s) {
        int n = s.size();
        vector<int> dp(n+1, -1);
        return f(s, 0, dp);
    }
};
