class Solution {
public:

    int dfs(vector<vector<int>>& grid, int i, int j, vector<vector<int>>& dp){
        if(i==0&&j==0)return dp[i][j]=grid[i][j];
        if(i<0||j<0)return INT_MAX;
        if(dp[i][j]!=-1)return dp[i][j];
        int up = dfs(grid, i-1, j, dp);
        int left = dfs(grid, i, j-1, dp);
        return dp[i][j]=grid[i][j]+min(up, left);
    }

    int minPathSum(vector<vector<int>>& grid) {
        int m = grid.size();
        int n = grid[0].size();
        vector<vector<int>> dp(m, vector<int>(n, -1));
        return dfs(grid, m-1, n-1, dp);
    }
};