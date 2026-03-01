class Solution {
public:
    // int dfs(int i, int canbuy, vector<int>& prices, int fee, vector<vector<int>>& dp){
    //     if(i==prices.size())return 0;
    //     if(dp[i][canbuy]!=-1)return dp[i][canbuy];
    //     // Check if you can buy a stock
    //     if(canbuy){
    //         /*
    //         If you can buy a stock, you have two options:
    //         1. Buy a stock and sell in future
    //         2. Skip buying it today and buy it in future
    //         Return max out of these two options
    //         */
    //         return dp[i][canbuy]=max(-prices[i]+dfs(i+1, 0, prices, fee, dp), dfs(i+1, 1, prices, fee, dp));
    //     }
    //     else{
    //         /*
    //         If you can sell a stock, you have two options:
    //         1. Sell a stock and buy in future with fee
    //         2. Skip selling it today and sell it in future
    //         Return max out of these two options
    //         */
    //         return dp[i][canbuy]=max(prices[i]-fee+dfs(i+1,1,prices,fee, dp), dfs(i+1, 0, prices, fee, dp));
    //     }
    // }
    int maxProfit(vector<int>& prices, int fee) {
        /*
        You can do any transaction
        but with the following conditions:
        1. You can hold at most 1 stock
        2. But one condition for every transaction you must pay fee
        */
        int n = prices.size();
        int aheadbuy =0;
        int aheadsell=0;
        vector<vector<int>> dp(n+1, vector<int>(2, 0));
        // return dfs(0, 1, prices, fee, dp);
        for(int i=n-1; i>=0; i--){
            int currbuy = max(-prices[i]+aheadsell, aheadbuy);
            int currsell = max(prices[i]-fee+aheadbuy, aheadsell);
            aheadbuy = currbuy;
            aheadsell = currsell;
        }
        return aheadbuy;
    }
};