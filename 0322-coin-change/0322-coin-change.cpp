class Solution {
public:
    // int dfs(int i, vector<int>& coins, int amount, vector<vector<int>>& dp){
    //     if(dp[i][amount]!=-1)return dp[i][amount];
    //     if(amount==0)return dp[i][amount]=0;
    //     if(i==0){
    //         if(amount%coins[0]==0)return dp[i][amount]=amount/coins[0];
    //         return 1e9;
    //     }
    //     int not_pick = dfs(i-1, coins, amount, dp);
    //     int pick = 1e9;
    //     if(coins[i]<=amount){
    //         pick = 1+dfs(i, coins, amount-coins[i], dp);
    //     }
    //     return dp[i][amount]=min(pick, not_pick);
    // }

    int coinChange(vector<int>& coins, int amount) {
        int n = coins.size();
        vector<vector<int>> dp(n, vector<int>(amount+1, 1e9));
        // int result = dfs(n-1, coins, amount, dp);
        // return result==1e9?-1:result;
        for(int i=0; i<n; i++){
            dp[i][0]=0;
        }
        for(int j=1; j<=amount; j++){
            if(j%coins[0]==0)dp[0][j]=j/coins[0];
        }
        for(int i=1; i<n; i++){
            for(int j=1; j<=amount; j++){
                int not_pick = dp[i-1][j];
                int pick = 1e9;
                if(coins[i]<=j){
                    pick = 1+dp[i][j-coins[i]];
                }
                dp[i][j]=min(pick, not_pick);
            }
        }
        return dp[n-1][amount]==1e9?-1:dp[n-1][amount];
    }
};