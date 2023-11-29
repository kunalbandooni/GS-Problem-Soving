// https://leetcode.com/problems/number-of-islands/

class Solution {
    void dfs(int i, int j, int n, int m, vector<vector<char>> &grid){
        if(i<0 or j<0 or i==n or j==m or grid[i][j] == '0')
            return;
        grid[i][j] = '0';
        dfs(i+1, j, n, m, grid);
        dfs(i, j+1, n, m, grid);
        dfs(i-1, j, n, m, grid);
        dfs(i, j-1, n, m, grid);
    }
    public:
    int numIslands(vector<vector<char>>& grid) {
        int count_of_islands = 0;
        int n = grid.size(), m = grid[0].size();
        
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(grid[i][j] == '1'){
                    dfs(i, j, n, m, grid);
                    count_of_islands++;
                }
            }
        }
        
        return count_of_islands;
    }
};
