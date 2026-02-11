class Solution {
public:
    int dfs(int i, int canbuy, vector<int>& prices, int n, vector<vector<int>>& dp){
        if(i==n)return 0;
        // check if you are holding a stock
        if(dp[i][canbuy]!=-1)return dp[i][canbuy];
        if(canbuy){
            return dp[i][canbuy]=max(-prices[i]+dfs(i+1, 0, prices, n, dp), dfs(i+1, 1, prices, n, dp));
        }
        else{
            return dp[i][canbuy]=max(prices[i]+dfs(i+1, 1, prices, n, dp), dfs(i+1, 0, prices, n, dp));
        }
    }
    int maxProfit(vector<int>& prices) {
        vector<vector<int>> dp(prices.size(), vector<int>(2, -1));
        return dfs(0, 1, prices, prices.size(), dp);
    }
};
/*
prices[] - ith ele in the prices array represent the stock price
Decide either sell/buy a stock
1 - 5 -> 4
3 - 6 -> 3
7
*/
