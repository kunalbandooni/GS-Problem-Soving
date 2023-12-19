// https://leetcode.com/problems/path-with-maximum-gold

class Solution {
    int helper(int i, int j, vector<vector<int>> &grid) {
        if(i < 0 || j < 0 || i >= grid.size() || j >= grid[0].size() || grid[i][j] <= 0)    return 0;
        
        grid[i][j] = -grid[i][j];
        
        int res = max({helper(i+1, j, grid),
                        helper(i, j+1, grid),
                        helper(i-1, j, grid),
                        helper(i, j-1, grid)});
        
        grid[i][j] = -grid[i][j];
        return res + grid[i][j];
    }
public:
    int getMaximumGold(vector<vector<int>>& grid) {
        int res = 0;
        for(int i = 0; i < grid.size(); i++)
            for(int j = 0; j < grid[0].size(); j++)
                res = max(res, helper(i, j, grid));
        return res;
    }
};
