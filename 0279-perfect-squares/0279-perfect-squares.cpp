class Solution {
public:

    // int dfs(int n, vector<int>& dp){
    //     if(n==0)return 0;
    //     if(dp[n]!=-1)return dp[n];
    //     int ans = 1e9;
    //     for(int i=1; i*i<=n; i++){
    //         ans = min(ans, 1+dfs(n-(i*i), dp));
    //     }
    //     return dp[n]=ans;
    // }

    int numSquares(int n) {
        vector<int> dp(n+1, 1e9);
        dp[0]=0;
        // return dfs(n, dp);
        for(int i=1; i<=n; i++){
            for(int j=1; j*j<=i; j++){
                dp[i] = min(dp[i], 1+dp[(i-(j*j))]);
            }
        }
        return dp[n];
    }
};
// 5

// dp[0 , 1 , 2, 3, 1, 2]
