class Solution {
public:

    // int dfs(int i, int j, vector<int>& nums, vector<vector<int>>& dp){
    //     if(j-i<=1)return dp[i][j]=0;
    //     int cost = 0;
    //     for(int k=i+1; k<j; k++){
    //         cost = max(cost, 
    //         nums[i]*nums[k]*nums[j]+
    //         dfs(i, k, nums, dp)+dfs(k, j, nums, dp)
    //         );
    //     }
    //     return dp[i][j]=cost;
    // }

    int maxCoins(vector<int>& nums) {
        // Insert the boundaries 1 at both the ends
        nums.insert(nums.begin(), 1);
        nums.push_back(1);
        int n = nums.size();
        vector<vector<int>> dp(n, vector<int>(n, 0));
        // return dfs(0, nums.size()-1, nums, dp);
        for(int i=n-1; i>=0; i--){
            for(int j=i+1; j<n; j++){
                if(j-i<=1)continue;
                int cost = 0;
                for(int k=i+1; k<j; k++){
                    cost = max(cost, 
                    nums[i]*nums[k]*nums[j]+
                    dp[i][k]+dp[k][j]
                    );
                }
                dp[i][j]=cost;
            }
        }
        return dp[0][n-1];
    }
};