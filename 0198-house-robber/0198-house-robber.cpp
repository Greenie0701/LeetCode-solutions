class Solution {
public:
    // int dfs(int index, vector<int>& nums, vector<int>& dp){
    //     if(index==0)return dp[0]=nums[0];
    //     if(index<0)return 0;
    //     if(dp[index]!=-1)return dp[index];
    //     int not_pick = dfs(index-1, nums, dp);
    //     int pick = nums[index]+dfs(index-2, nums, dp);
    //     return dp[index]=max(pick, not_pick);
    // }
    int rob(vector<int>& nums) {
        if(nums.size()==1){
            return nums[0];
        }
        int n = nums.size();
        vector<int> dp(n, 0);
        dp[0]=nums[0];
        dp[1]=max(nums[0], nums[1]);
        for(int i=1; i<n; i++){
            int not_pick = dp[i-1];
            int pick = 0;
            if(i>1){
                pick = nums[i]+dp[i-2];
            }
            dp[i]=max(not_pick, pick);
        }
        return dp[n-1];
        // return dfs(n-1, nums, dp);
    }
};

// 1 2 3 1
//     3 1 = 4
//     2 1 = 3