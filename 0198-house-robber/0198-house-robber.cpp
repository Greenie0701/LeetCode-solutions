class Solution {
public:

    // int dfs(int i, vector<int>& nums, vector<int>& dp){
    //     if(i<0)return 0;
    //     if(dp[i]!=-1)return dp[i];
    //     if(i==0)return dp[i]=nums[0]; 
    //     int not_pick = dfs(i-1, nums, dp);
    //     int pick = nums[i]+dfs(i-2, nums, dp);
    //     return max(pick, not_pick);
    // }


    int rob(vector<int>& nums) {
        int n = nums.size();
        if(n==1)return nums[0];
        vector<int> dp(n, 0);
        // return dfs(n-1, nums, dp);
        dp[0]=nums[0];
        dp[1]=max(nums[0], nums[1]);
        for(int i=2; i<n; i++){
            int not_pick = dp[i-1];
            int pick = 0;
            if(i>1){
                pick = nums[i]+dp[i-2];
            }
            dp[i]=max(pick, not_pick);
        }
        return dp[n-1];
    }
};