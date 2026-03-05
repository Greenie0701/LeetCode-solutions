class Solution {
public:
    int mod =1e9 + 7;
    int dfs(int len, int low, int high, int zero, int one, vector<int>& dp){
        if(len>high)return 0;
        if(dp[len]!=-1)return dp[len];
        long long ans = 0;
        if(len>=low)ans++;
        ans+=dfs(len+zero, low, high, zero, one, dp);
        ans+=dfs(len+one, low, high, zero, one, dp);

        return dp[len]=ans%mod;
    }

    int countGoodStrings(int low, int high, int zero, int one) {
        vector<int> dp(high+1, -1);
        return dfs(0, low, high, zero, one, dp);
    }
};