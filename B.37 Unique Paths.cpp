// https://leetcode.com/problems/unique-paths

class Solution {
    int f(int i, int j, int m, int n, vector<vector<int>> &dp) {
        if(i > m || j > n)   return 0;
        if(i == m && j == n) return 1;
        if(dp[i][j] != -1)  return dp[i][j];
        int right = f(i+1, j, m, n, dp);
        int down = f(i, j+1, m, n, dp);
        return dp[i][j] = right + down;
    }
public:
    int uniquePaths(int m, int n) {
        vector<vector<int>> dp(m+1, vector<int> (n+1, -1));
        return f(1, 1, m, n, dp);
    }
};
