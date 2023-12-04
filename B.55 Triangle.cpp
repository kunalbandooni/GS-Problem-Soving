// https://leetcode.com/problems/triangle

class Solution {
    int f(int i, int j, vector<vector<int>>& triangle, vector<vector<int>>& dp) {
        if (i == triangle.size())   return 0;
        if (j == triangle[i].size())   return 0;
        if (dp[i][j] != -1) return dp[i][j];
        int left = f(i + 1, j, triangle, dp);
        int right = f(i + 1, j + 1, triangle, dp);
        return dp[i][j] = triangle[i][j] + min(left, right);
    }
public:
    int minimumTotal(vector<vector<int>>& triangle) {
        int n = triangle.size();
        vector<vector<int>> dp(n, vector<int> (n, -1));
        return f(0, 0, triangle, dp);
    }
};
