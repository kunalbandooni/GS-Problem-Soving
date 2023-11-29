// https://leetcode.com/problems/minimum-path-sum/

class Solution {
    int dp[210][210];
    int f(int i, int j, int n, int m, vector<vector<int>> grid) {
        if(i >= n || j >= m)
            return 1e9;

        if(i == n-1 && j == m-1) 
            return grid[i][j];
        
        if(dp[i][j] != -1) 
            return dp[i][j];

        int up = f(i+1, j, n, m, grid);
        int left = f(i, j+1, n, m, grid);

        return dp[i][j] = grid[i][j] + min(up, left);
    }
public:
    int minPathSum(vector<vector<int>>& grid) {
        for(int i = 0; i < 210; i++)
            for(int j = 0; j < 210; j++)
                dp[i][j] = 0;
        int n = grid.size();
        int m = grid[0].size();

        // return f(0, 0, n, m, grid);
        
        dp[0][0]=grid[0][0];
        for(int i=1;i<m;i++)
            dp[0][i]=dp[0][i-1]+grid[0][i];
        
        for(int i=1;i<n;i++) 
            dp[i][0]=dp[i-1][0]+grid[i][0];
        
        for(int i=1;i<n;i++) 
            for(int j=1;j<m;j++)
                dp[i][j] = min(dp[i-1][j],dp[i][j-1]) + grid[i][j];
        
        return dp[n-1][m-1];
    }
};
