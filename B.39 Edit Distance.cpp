// https://leetcode.com/problems/edit-distance

class Solution {
    int f(int i, int j, string word1, string word2, vector<vector<int>> &dp) {
        if(i < 0)   return j + 1;  // remaining length
        if(j < 0)   return i + 1;  // remaining length

        if(dp[i][j] != -1)
            return dp[i][j];

        if(word1[i] == word2[j])
            return f(i-1, j-1, word1, word2, dp);

        int delete_ = f(i-1, j, word1, word2, dp);
        int insert_ = f(i, j-1, word1, word2, dp);
        int replace = f(i-1, j-1, word1, word2, dp);

        return dp[i][j] = 1 + min(delete_, min(insert_, replace));
    }
public:
    int minDistance(string word1, string word2) {
        int n = word1.length();
        int m = word2.length();
        vector<vector<int>> dp(n, vector<int> (m, -1));
        return f(n-1, m-1, word1, word2, dp);
    }
};
