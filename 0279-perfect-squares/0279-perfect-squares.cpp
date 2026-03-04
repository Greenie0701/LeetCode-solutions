class Solution {
public:
    int dfs(int n){
        if(n<=0)return 0;
        int ans = 1e9;
        for(int i=1; i*i<=n; i++){
            ans = min(ans, 1+dfs(n-(i*i)));
        }
        return ans;
    }

    int numSquares(int n) {
        // return dfs(n);
        vector<int> dp(n+1, 1e9);
        dp[0]=0;
        for(int i=1; i<=n; i++){
            for(int j=1; j*j<=i; j++){
                dp[i]  = min(dp[i], 1+dp[i-(j*j)]);
            }
        }
        return dp[n];
    }
};