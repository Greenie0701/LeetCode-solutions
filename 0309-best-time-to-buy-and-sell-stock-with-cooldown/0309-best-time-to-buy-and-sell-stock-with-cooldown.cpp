class Solution {
public:
    int dfs(int i, int canbuy, vector<int>& prices, int n, vector<vector<int>>& dp){
        if(i>=n)return 0;
        // Check if the dp is precomputed
        if(dp[i][canbuy]!=-1)return dp[i][canbuy];
        //Check you can buy a stock
        if(canbuy){
            return dp[i][canbuy]=max(
                -prices[i]+dfs(i+1, 0, prices, n, dp),
                dfs(i+1, 1, prices, n, dp)
            );
        }
        else{
            return dp[i][canbuy]=max(
                prices[i]+dfs(i+2, 1, prices, n, dp),
                dfs(i+1, 0, prices, n, dp)
            );
        }
    }
    int maxProfit(vector<int>& prices) {
        /*
        When you buy a stock, lets say you have 2 options basically:
        1. Buy stock 
        2. Sell stock - If you sell a stock, you can't buy it the i+1th stock(skip i+1th day)
        2 options+maximise the profit -> recursion
        */
        vector<vector<int>> dp(prices.size(), vector<int>(2, -1));
        return dfs(0, 1, prices, prices.size(), dp);

    }
};