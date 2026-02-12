class Solution {
public:
    int dfs(int i, int left, int canbuy, vector<int>& prices, int n, vector<vector<vector<int>>>& dp){
        // Check if there is any transaction left/No more stocks left to buy
        if(i==n||left==0)return 0;
        if(dp[i][canbuy][left]!=-1)return dp[i][canbuy][left];
        // Else
        if(canbuy){
            return dp[i][canbuy][left]=max(-prices[i]+dfs(i+1, left, 0, prices, n, dp),dfs(i+1, left, 1, prices, n, dp));
        }
        else{
            return dp[i][canbuy][left]=max(prices[i]+dfs(i+1, left-1, 1, prices, n, dp), dfs(i+1, left, 0, prices, n, dp));
        }
    }
    int maxProfit(vector<int>& prices) {
        /*
        The question is all about finding the maximum profit you can
        by selling 2 transactions. Note than we can buy/sell 2 stocks
        at a time. 1 transaction = buy & sell them.
        so you can do buy1 -> sell1 ->buy2 -> sell2
        You task is to find the maximum profit by making these 2 transactions
        */
        /* The dfs function explores all the possible way to either pick ith day stock
           and sell/buy/skip the day based upon the following crieterias
           1. left -> Check if we have transactions left
           2. i -> Track the ith day in prices
           3. prices
           4. Can_buy -> Track whether you can buy the stock
        */
        int n = prices.size();
        vector<vector<vector<int>>> dp(n, vector<vector<int>>(2, vector<int>(3, -1)));
        return dfs(0, 2, 1, prices, n, dp);
    }
};