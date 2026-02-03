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
        vector<int> prev(amount+1, INF);
        // int ans = dfs(n-1, coins, amount, dp);
        // return ans>=INF?-1:ans;
        for (int t = 1; t <= amount; t++) {
            if (t % coins[0] == 0)
                prev[t] = t / coins[0];
        }
        prev[0]=0;
        for(int i=1; i<n; i++){
            vector<int> curr(amount+1, INF);
            curr[0]=0;
            for(int t=1; t<amount+1; t++){
                int not_pick = prev[t];
                int pick = INF;
                if(coins[i]<=t){
                    pick = 1+curr[t-coins[i]];
                }
                curr[t]=min(not_pick, pick);
            }
            prev = curr;
        }
        return prev[amount]==INF?-1:prev[amount];
    }
}; 
