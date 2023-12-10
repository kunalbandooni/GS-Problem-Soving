// https://leetcode.com/problems/minimum-falling-path-sum

class Solution {
    int f (int i, int j, vector<vector<int>>& matrix, 
                            vector<vector<int>>& dp) {
        if (j < 0 or j >= matrix.size())
            return 1e8;
        if (i == 0) return matrix[0][j];

        if (dp[i][j] != -1) return dp[i][j];

        int up = 1e8, left = 1e8, right = 1e8;
        
        up = f(i-1, j, matrix, dp);
        if (j > 0)
            left = f(i-1, j-1, matrix, dp);
        if (j < matrix.size()-1)
            right = f(i-1, j+1, matrix, dp);

        return dp[i][j] = matrix[i][j] + min(up, min(left, right));
    }
public:
    int minFallingPathSum(vector<vector<int>>& matrix) {
        int n = matrix.size();
        int m = matrix[0].size();

        vector<vector<int>> dp(n, vector<int> (m, -1));

        int mini = INT_MAX;
        for(int j = 0; j < m; j++) {
            mini = min(mini, f(n-1, j, matrix, dp));
        }

        return mini;
    }
};
