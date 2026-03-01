class Solution {
public:

    int dfs(int i, int j, vector<int>& cuts, vector<vector<int>>& dp){
        if(j-i<=1)return 0;
        if(dp[i][j]!=-1)return dp[i][j];
        int cost = INT_MAX;
        for(int k=i+1; k<j; k++){
            cost = min(cost, dfs(i, k, cuts, dp)+dfs(k, j, cuts, dp)+cuts[j]-cuts[i]);
        }
        return dp[i][j]=cost;
    }

    int minCost(int n, vector<int>& cuts) {
        cuts.push_back(0);
        cuts.push_back(n);
        vector<vector<int>> dp(cuts.size(), vector<int>(cuts.size(), -1));
        sort(cuts.begin(), cuts.end());
        return dfs(0, cuts.size()-1, cuts, dp);
    }
};