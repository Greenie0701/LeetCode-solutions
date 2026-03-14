class Solution {
public:
    int dfs(int i, vector<int>& coins, int amount, vector<vector<int>>& dp){
        if(dp[i][amount]!=-1)return dp[i][amount];
        if(amount==0)return dp[i][amount]=0;
        if(i==0){
            if(amount%coins[0]==0)return dp[i][amount]=amount/coins[0];
            return 1e9;
        }
        int not_pick = dfs(i-1, coins, amount, dp);
        int pick = 1e9;
        if(coins[i]<=amount){
            pick = 1+dfs(i, coins, amount-coins[i], dp);
        }
        return dp[i][amount]=min(pick, not_pick);
    }

    int coinChange(vector<int>& coins, int amount) {
        int n = coins.size();
        vector<vector<int>> dp(n, vector<int>(amount+1, -1));
        int result = dfs(n-1, coins, amount, dp);
        return result==1e9?-1:result;
    }
};