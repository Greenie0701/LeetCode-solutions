class Solution {
public:

    // int dfs(int i, int prev, vector<int>& nums, int n, vector<vector<int>>& dp){
    //     if(i==n)return 0;
    //     if(dp[i][prev+1]!=-1){
    //         return dp[i][prev+1];
    //     }
    //     // Skip the index
    //     int not_pick = dfs(i+1, prev, nums, n, dp);
    //     // Try to pick the index
    //     int pick = 0;
    //     // Check if the conditions are made
    //     if(prev==-1||nums[prev]<nums[i]){
    //         pick=1+dfs(i+1, i, nums, n, dp);
    //     }
    //     // Return the max of you choice
    //     return dp[i][prev+1]=max(pick, not_pick);
    // }

    int lengthOfLIS(vector<int>& nums) {
        /*
        The best way to solve the problem is to us recursion
        How recursion can be used here?
        For every index i and prev, there could be two chance:
        1. You can either pick the index i if the following condition made:
            prev<i &&arr[prev]<arr[i]
        2. You can skip the index and move to the next index
        */
        int n = nums.size();
        vector<int> curr(n+1, 0);
        vector<int> ahead(n+1, 0);
        // return dfs(0, -1, nums, n, dp);
        for(int i=n-1; i>=0; i--){
            for(int prev=i-1; prev>=-1; prev--){
                int not_pick = ahead[prev+1];
                // Try to pick the index
                int pick = 0;
                // Check if the conditions are made
                if(prev==-1||nums[prev]<nums[i]){
                    pick=1+ahead[i+1];
                }
                //the max of you choice
                curr[prev+1]=max(pick, not_pick);
            }
            ahead = curr;
        }
        return ahead[0];
    }
};
 