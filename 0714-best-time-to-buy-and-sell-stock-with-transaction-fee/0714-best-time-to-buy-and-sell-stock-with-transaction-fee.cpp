class Solution {
public:
    
    // int dfs(int i, int canbuy, vector<int>& prices, int fee, int& n){
    //     if(i==n)return 0;
    //     // Every day you can either buy a stock or sell stock based on the canbuy
    //     if(canbuy){
    //         return max(-prices[i]+dfs(i+1, 0, prices, fee, n), dfs(i+1, 1, prices, fee, n));
    //     }
    //     else{
    //         return max(prices[i]-fee+dfs(i+1, 1, prices, fee, n), dfs(i+1, 0, prices, fee, n));
    //     }
    // }

    int maxProfit(vector<int>& prices, int fee) {
        int n = prices.size();
        // return dfs(0, 1, prices, fee, n);
        vector<vector<int>> dp(n+1, vector<int>(2, 0));
        for(int i=n-1; i>=0; i--){
            dp[i][1]=max(-prices[i]+dp[i+1][0], dp[i+1][1]);
            dp[i][0]=max(prices[i]-fee+dp[i+1][1],dp[i+1][0]);
        }
        return dp[0][1];
    }
};