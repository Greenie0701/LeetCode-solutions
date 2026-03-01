class Solution {
public:
    // int dfs(int i, int j,  vector<int>& cuts, vector<vector<int>>& dp){
    //     if(j-i<=1)return dp[i][j]=0;
    //     if(dp[i][j]!=-1)return dp[i][j];
    //     // try cutting every pos
    //     int cost = 1e9;
    //     for(int k=i+1; k<j; k++){
    //         cost = min(cost, cuts[j]-cuts[i]+dfs(i, k, cuts, dp)+dfs(k, j, cuts, dp));
    //     }
    //     return  dp[i][j]=cost;
    // }
    int minCost(int n, vector<int>& cuts) {
        cuts.push_back(0);
        cuts.push_back(n);
        vector<vector<int>> dp(cuts.size(), vector<int>(cuts.size(), 0));
        sort(cuts.begin(), cuts.end());
        // return dfs(0, cuts.size()-1, cuts, dp);
        for(int i=cuts.size()-1; i>=0; i--){
            for(int j=i+1; j<cuts.size(); j++){
                if(j-i<=1)continue;
                int cost = 1e9;
                for(int k=i+1; k<j; k++){
                    cost = min(cost, cuts[j]-cuts[i]+dp[i][k]+dp[k][j]);
                }
                dp[i][j]=cost;
            }
        }
        return dp[0][cuts.size()-1];
    }
};