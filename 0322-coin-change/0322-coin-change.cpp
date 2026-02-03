class Solution {
public:
    int INF = 1e9;
    int dfs(int index, vector<int>& coins, int amount, vector<vector<int>>& dp){
        if(index==0){
            if(amount%(coins[0])==0)return(dp[index][amount]=amount/(coins[0]));
            return INF;
        }
        if(index<0||amount<0)return INF;
        if(dp[index][amount]!=-1)return dp[index][amount];
        int not_pick = dfs(index-1, coins, amount, dp);
        int pick = INF;
        if(coins[index]<=amount){
            pick = 1+dfs(index, coins, amount-coins[index], dp);
        }
        return dp[index][amount]=min(not_pick, pick);
    }
    int coinChange(vector<int>& coins, int amount) {
        int n=coins.size();
        vector<vector<int>> dp(n, vector<int>(amount+1, -1));
        int ans = dfs(n-1, coins, amount, dp);
        return ans>=INF?-1:ans;
    }
};