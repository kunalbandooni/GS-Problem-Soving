// https://leetcode.com/problems/number-of-provinces

class Solution {
    void dfs(int j, vector<bool> &vis, vector<int> adj[]) {
        vis[j] = true;
        for(auto x: adj[j])
            if(!vis[x])
                dfs(x, vis, adj);
    }
public:
    int findCircleNum(vector<vector<int>>& isConnected) {
        int count = 0;
        int n = isConnected.size();
        vector<int> adj[n];
        vector<bool> vis(n, false);

        for(int i = 0; i < n; i++)
            for(int j = 0; j < n; j++)
                if(isConnected[i][j] == 1 && i!=j)
                    adj[i].push_back(j);

        for(int i = 0; i < n; i++) {
            if(!vis[i]) {
                dfs(i, vis, adj);
                count++;
            }
        }

        return count;
    }
};
