class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int n = prices.size();
        vector<vector<int>> dp(n+1, vector<int>(2, 0));

        for(int i=n-1; i>=0; i--){
            // Buy the stock and sell it in future
            dp[i][1] = max(-prices[i]+dp[i+1][0], dp[i+1][1]);
            // Going to sell the stock
            dp[i][0] = max(prices[i]+dp[i+1][1], dp[i+1][0]);
        }
        return dp[0][1];
    }
};