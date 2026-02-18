class Solution {
public:
    int dfs(int i, int j, vector<vector<int>>& dp){
        // No way to can reach starting point if you are out of bounds
        if(i<0||j<0)return 0;
        // Check if the value is precomputed
        if(dp[i][j]!=-1)return dp[i][j];
        // Check if you can reached the dest(0, 0)
        if(i==0&&j==0)return dp[i][j]=1;
        // Else you have two choice
        int up = dfs(i-1, j, dp);
        int left = dfs(i, j-1, dp);
        // Return the count 
        return dp[i][j]=up+left;
    }
    int uniquePaths(int m, int n) {
        vector<vector<int>> dp(m, vector<int>(n, -1));
        return dfs(m-1, n-1, dp);
    }
};